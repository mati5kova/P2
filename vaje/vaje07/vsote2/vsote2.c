#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int vsota(int trenutnaVsota, int cilj, int zgornjaMeja, int* zaporedje, int dolzina)
{
	if(trenutnaVsota == cilj)
	{
		for(int k = 0; k < dolzina; k++)
		{
			printf("%d", zaporedje[k]);
			if(k != dolzina - 1)
			{
				printf(" + ");
			}
		}
		printf("\n");
		return 1;
	} else if(trenutnaVsota > cilj)
	{
		return 0;
	}
	
	int stevilo = 0;
	for(int i = zgornjaMeja; i >= 1; i--)
	{
		int* tempZaporedje = calloc(dolzina+1, sizeof(int));
		for(int k = 0; k < dolzina; k++)
		{
			tempZaporedje[k] = zaporedje[k];
		}
		tempZaporedje[dolzina] = i;
		
		stevilo += vsota(trenutnaVsota + i, cilj, i, tempZaporedje, dolzina + 1);
		free(tempZaporedje);
	}
	return stevilo;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int* zaporedje = calloc(n, sizeof(int));
	
	vsota(0, n, k, zaporedje, 0);
	
	free(zaporedje);
	return 0;
}