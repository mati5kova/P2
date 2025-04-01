#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
    // popravite / dopolnite
	int stElementov = izvornoStVrstic * N;
	
	int** t = malloc(ciljnoStVrstic * sizeof(int*));
	if(t == NULL){return NULL;}
	
	for(int i = 0; i < ciljnoStVrstic; i++)
	{
		t[i] = malloc((stElementov / ciljnoStVrstic + 1) * sizeof(int));
		if(t[i] == NULL)
		{
			for(int k = 0; k < i; k++)
			{
				free(t[k]);
			}
			free(t);
			return NULL;
		}
	}
	
	int indeksVrstica = 0, indeksStolpec = 0, indeksOgTabele = 0;
	
	for(int i = 0; i < ciljnoStVrstic; i++)
	{
		for(int k = 0; k < (stElementov / ciljnoStVrstic); k++)
		{
			t[indeksVrstica][indeksStolpec] = kazalec[indeksOgTabele / N][indeksOgTabele % N];
			indeksOgTabele++;
			indeksStolpec++;
		}
		t[indeksVrstica][indeksStolpec] = 0;
		indeksVrstica++;
		indeksStolpec = 0;
	}

    return t;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    // popravite / dopolnite
	int stElementov = 0;
	for(int i = 0; i < izvornoStVrstic; i++)
	{
		int stolpec = 0;
		while(kazalec[i][stolpec] != 0)
		{
			stElementov++;
			stolpec++;
		}
	}
	
	int stElDivByN = stElementov / N;
	*ciljnoStVrstic = stElDivByN + (stElDivByN * N == stElementov ? 0 : 1);
		
	int (*t)[N] = malloc(sizeof(int[*ciljnoStVrstic][N]));
	if(t == NULL) {return NULL;}
	
	int vrsticaNovo = 0, stolpecNovo = 0;
	
	for(int i = 0; i < izvornoStVrstic; i++)
	{
		int stolpecStaro = 0;
		while(kazalec[i][stolpecStaro] != 0)
		{
			t[vrsticaNovo][stolpecNovo] = kazalec[i][stolpecStaro];
			++stolpecNovo;
			
			if(stolpecNovo == N)
			{
				stolpecNovo = 0;
				vrsticaNovo++;
			}

			stolpecStaro++;
		}
	}
	//preostali prostor zapolnimo z niclami
	while(vrsticaNovo*N + stolpecNovo != *ciljnoStVrstic * N)
	{
		t[vrsticaNovo][stolpecNovo] = 0;
		stolpecNovo++;
	}
	
    return t;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
	return 0;
}

#endif
