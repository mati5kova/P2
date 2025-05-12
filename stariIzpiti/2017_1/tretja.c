#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void pisi(int** t, int n, int indeks1, int* stevilo, int dolzina)
{
	if(indeks1 >= n)
	{
		for(int i = 0; i < n; i++)
			printf("%d", stevilo[i]);
		printf("\n");
		
		return;
	}
	
	for(int i = t[indeks1][0]; i <= t[indeks1][1]; i++)
	{
		stevilo[dolzina] = i;
		pisi(t, n, indeks1 + 1, stevilo, dolzina + 1);
	}
}

int main()
{
	int n; scanf("%d", &n);
	int** t = malloc(n * sizeof(int*));
	
	for(int i = 0; i < n; i++)
	{
		t[i] = malloc(2 * sizeof(int));
		scanf("%d %d", &(t[i][0]), &(t[i][1]));
	}
	
	int* temp = malloc(n * sizeof(int));
	pisi(t, n, 0, temp, 0);
	
	
	for(int i = 0; i < n; i++)
		free(t[i]);
	free(t);
	free(temp);
	
	return 0;
}