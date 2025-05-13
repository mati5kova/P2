#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MEJA 8

int polje[MEJA][MEJA];

typedef struct _Pozicija {
	int vrstica;
	int stolpec;
} Pozicija;

void izpisiPolje()
{
	for(int i = 0; i < MEJA; i++)
	{
		for(int j = 0; j < MEJA; j++)
			printf("%d ", polje[i][j]);
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int* ukazi = malloc(n * sizeof(int));
	
	Pozicija p = { 7, 7 };
	polje[p.vrstica][p.stolpec] = 1;
	
	int vektorStolpec[] = {-1, 0, 1, 0};
	int vektorVrstica[] = {0, -1, 0, 1};
	
	for(int i = 0; i < n; i++)
		scanf("%d", &(ukazi[i]));
	
	for(int i = 0; i < n; i++)
	{
		int novaVrstica = p.vrstica + vektorVrstica[ukazi[i]];
		int novStolpec = p.stolpec + vektorStolpec[ukazi[i]];
		
		if(novaVrstica >= 0 && novaVrstica < MEJA && novStolpec >= 0 && novStolpec < MEJA)
		{
			p.vrstica = novaVrstica;
			p.stolpec = novStolpec;
			polje[p.vrstica][p.stolpec] = 1;
		}
	}
	
	long long unsigned int rezultat = 0;
	
	for(int i = 0; i < MEJA; i++)
	{
		for(int j = 0; j < MEJA; j++)
		{
			rezultat = rezultat * 2 + polje[i][j];
		}
	}
	
	izpisiPolje();
	
	printf("64b število v [10]: %llu\n", rezultat);
	
	free(ukazi);
	
	return 0;
}