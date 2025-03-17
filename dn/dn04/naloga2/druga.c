#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void napolniTabelo(int t[], int stElementov)
{
	int st;
	for(int i = 0; i < stElementov; i++)
	{
		scanf("%d", &st);
		t[i] = st;
	}
}

int main()
{
	int n, k, i, j;
	long stParov = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	
	int *t = (int*) malloc(n * sizeof(int));
	napolniTabelo(t, n);
	
	long notranjeSteviloParov = 0;
	bool konec = false;
	
	for(i = 0; i < n && !konec; i++)
	{
		
		if(i > 0 && t[i] == t[i - 1])
		{
			//memoizacija, da ne loopamo ce se na levi strani arraya ponavljajo elemnti
			//
			//pristejemo stevilo ustreznih parov ki so bili izracunani prvic s takim elemntom
			stParov += notranjeSteviloParov;
			continue;
		} else
		{
			//ce se element na levi strani spremeni
			notranjeSteviloParov = 0;
		}
		
		for(j = n - 1; j > i; j--)
		{
			if(t[i] + t[j] == k)
			{
				//ce smo recimo nekje na sredini ko npr. iscemo vsoto 10 in je samo zaporedje stevil 5
				//(j - i)-krat pristejemo (j - i)--
				//
				//npr. input:
				//5 2
				//1 1 1 1 1
				//4+3+2+1 = [10]
				if(t[i] == t[j])
				{
					
					int razlika = j - i;
					while(razlika)
					{
						notranjeSteviloParov += (razlika--);
					}
					konec = true;
					//breakamo ven ker ce sestevamo elementa ki sta enaka in dobimo pravo vsoto
					//nimamo vec kaj za gledat
					break;
				}
				
				notranjeSteviloParov++;
				
			} else if(t[i] + t[j] < k)
			{
				//ni treba vec gledat ce je vsota manjsa
				//(to lahko ker je array v narascajocem vrstnem redu)
				break;
			}
		}
		stParov += notranjeSteviloParov;
	}
	
	printf("%ld\n", stParov);
	
	free(t);
	return 0;
}
