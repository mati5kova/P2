#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool igraj(int preostaliZetoni, int k, bool beliNaPotezi, int* poteze, int steviloOdigranihPotez, bool izpisujZmage)
{
	
	
	if(preostaliZetoni == 0)
	{
		if(!beliNaPotezi && izpisujZmage)
		{
			for(int i = 0; i < steviloOdigranihPotez; i++)
			{
				if(i % 2 == 0)
					printf("%d", poteze[i]);
				else
					printf("[%d]", poteze[i]);
				if(i != steviloOdigranihPotez - 1)
					printf(" -> ");
			}
		printf("\n");
		}
		
		// vrne true ce je beli zmagal (torej je trenutno crni na potezi)
		return !beliNaPotezi;
		
	} else if(preostaliZetoni < 0)
	{
		// nikoli ne pride do tega, samo za debugiranje
		printf("neveljavna poteza\n");//neveljavna poteza
	}
	
	if(beliNaPotezi)
	{
		bool zmagalVsajEno = false;
		for(int i = k; i >= 1; i--)
		{
			// ker se i zmanjsuje, ce je trenutno negativna vrednost pogledamo naslednjo
			if(preostaliZetoni - i < 0) continue;
			
			poteze[steviloOdigranihPotez] = i;
			bool beliJeZmagal = igraj(preostaliZetoni - i, k, !beliNaPotezi, poteze, steviloOdigranihPotez + 1, izpisujZmage);
			if(beliJeZmagal)
			{
				zmagalVsajEno = true;
				break;
			}
		}
		return zmagalVsajEno;
		
		
	} else 
	{
		if(preostaliZetoni - k <= 0) { return false; }
		
		for(int i = 1; i <= k; i++)
		{
			// ker se i povecuje, ce je vmes ze negativna vrednost 
			// 	nima smisla gledat naprej
			if(preostaliZetoni - i < 0) break; 
			
			poteze[steviloOdigranihPotez] = i;
			bool beliJeZmagal = igraj(preostaliZetoni - i, k, !beliNaPotezi, poteze, steviloOdigranihPotez + 1, izpisujZmage);
			
			if(!beliJeZmagal)
			{
				return false; // vrnemo false (v tem poddrevesu crni vsaj enkrat zmaga)
			}
		}
		return true;
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	bool beliKdajZmaga = false;
	
	for (int i = k; i >= 1; --i) {
		if(n - i < 0) continue;
		
		int* poteze = calloc(62, sizeof *poteze);
		poteze[0] = i;
		if (igraj(n - i, k, false, poteze, 1, false)) {
			igraj(n - i, k, false, poteze, 1, true);
			beliKdajZmaga = true;
		}
		free(poteze);
	}
	
	if (!beliKdajZmaga) {
		printf("CRNI\n");
	}
	
	return 0;
}
