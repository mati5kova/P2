#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define VELIKOST 10001

int beriVTabelo(int* t)
{
	int indeks = 0;
	char c;
	while((c = getchar()) != '\n' && c != EOF && c != ' ')
	{
		t[indeks++] = c - '0';
	}
	
	return indeks;
}

int main()
{
	int* t1 = calloc(VELIKOST, sizeof(int));
	int* t2 = calloc(VELIKOST, sizeof(int));
	
	int* rezultat = calloc(VELIKOST, sizeof(int));
	
	int v1 = beriVTabelo(t1);
	int v2 = beriVTabelo(t2);
	int dolzina = VELIKOST - 1;
	
	while(1)
	{
		int rez = 0;
		
		if(v1 > 0)
		{
			if(v2 > 0)
			{
				rez = t1[--v1] + t2[--v2];
			} else
			{
				rez = t1[--v1];
			}
		} else
		{
			if(v2 > 0)
			{
				rez = t2[--v2];
			} else
			{
				break;
			}
		}
		
		rezultat[dolzina] += rez;
		
		int tempDolzina = dolzina;
		
		while(rezultat[tempDolzina] > 9)
		{
			int ostanek = rezultat[tempDolzina] % 10;
			rezultat[tempDolzina] -= 10;
			rezultat[tempDolzina - 1]++;
			
			tempDolzina--;
		}			
		
		dolzina--;
	}
	
	bool jeZeBilaNeNula = false;
	for(int i = 0; i < VELIKOST; i++)
	{
		if(rezultat[i] != 0)
			jeZeBilaNeNula = true;
		if(jeZeBilaNeNula)
			printf("%d", rezultat[i]);
	}
	printf("\n");
	
	free(t1);
	free(t2);
	free(rezultat);
	
	
	return 0;
}