#include <stdio.h>
#include <stdlib.h>

void razbij(int* og, int n, int* podmnozica, int target, int trenutnaVsota, int indeks, int trenutnaDolzinaPodmnozice) 
{
	if(trenutnaVsota == target)
	{
		//izpisi podmnozico
		printf("{");
		for(int i = 0; i < trenutnaDolzinaPodmnozice; i++)
		{
			printf("%d", podmnozica[i]);
			if(i != trenutnaDolzinaPodmnozice - 1)
			{
				printf(", ");
			}
		}
		printf("}\n");
		return;
	} else if(trenutnaVsota > target || indeks >= n)
	{
		//slaba veja
		return;
	}
	
	//vzamemo trenutni element
	podmnozica[trenutnaDolzinaPodmnozice] = og[indeks];
	razbij(og, n, podmnozica, target, trenutnaVsota + og[indeks], indeks + 1, trenutnaDolzinaPodmnozice + 1);
	
	
	//ne vzamemo trenutnega elementa
	razbij(og, n, podmnozica, target, trenutnaVsota, indeks + 1, trenutnaDolzinaPodmnozice);
}


int main()
{
	int n, suma = 0;
	scanf("%d", &n);
	
	int* t = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		suma += t[i];
	}
	
	int pod[21];
	pod[0] = t[0]; //prvi element je vedno v tej podmnožici
	razbij(t, n, pod, suma / 2, pod[0], 1, 1);
	
	free(t);
	return 0;
}