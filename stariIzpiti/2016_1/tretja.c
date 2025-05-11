#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isci(int* t, int n, int indeks, int currMax, int* t2, int st)
{
	if(indeks >= n)
	{
		return 0; // ce smo na koncu vrni 0
	}
	
	if(currMax % t[indeks] == 0 || t[indeks] % currMax == 0)
	{
		t2[st++] = t[indeks];
		return 1 + isci(t, n, indeks + 1, currMax, t2, st); // se en element dodan, vrnemo 1 + nadaljnje iskanje
	} else
	{
		return isci(t, n, indeks + 1, currMax, t2, st); // ne vzamemo trenutnega, nadaljujemo iskanje
	}
}

int main()
{
	int n; scanf("%d\n", &n);
	int* t = malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++)
		scanf("%d", &(t[i]));
	
	
	int currMax = 0;
	for(int i = 0; i < n; i++)
	{
		int* t2 = malloc(n * sizeof(int)); // samo za potrebe vizualizacije
		int rez = isci(t, n, i, t[i], t2, 0);
	
		// vmesni izpis za vizualizacijo izbir
		for(int k = 0; k < n; k++)
			printf("%d ", t2[k]);
		printf("\n");
		
		if(rez > currMax)
			currMax = rez;
		
		free(t2);
	}
	
	printf("%d\n", currMax);
	
	free(t);
	
	return 0;
}