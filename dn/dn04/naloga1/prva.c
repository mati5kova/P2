#include <stdio.h>
#include <stdlib.h>

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
	int n;
	scanf("%d", &n);
	
	int *t1 = (int*) malloc(n * sizeof(int));
	int *t2 = (int*) malloc(n * sizeof(int));
	
	napolniTabelo(t1, n);
	napolniTabelo(t2, n);
	
	int indeks1 = 0, indeks2 = 0, offset = 0;
	
	while(1)
	{		
		if(indeks1 == n)
		{
			//indeks1 je prisel do konca, prestavimo ga na zacetek
			indeks1 = 0;
		}
		
		if(indeks2 == n - 1)
		{
			//indeks2 je prisel do konca -> tabeli se ujemata
			break;
		}
		
		if(t1[indeks1] == t2[indeks2])
		{
			//nadaljujemo gledat za ujemanje
			indeks1++;
			indeks2++;
		} else 
		{
			//elementa se ne ujemata, povecamo offset, ponastavimo indeks2 in nastavimo indeks1
			offset++;
			indeks1 = offset;
			indeks2 = 0;
		}
	}
	
	printf("%d\n", offset);
	
	free(t1);
	free(t2);
	
	return 0;
}