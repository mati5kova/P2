#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int* t, int n, int k1, int k2, int preostaliSkoki, int indeksPloscice)
{
	if(indeksPloscice < 0 || indeksPloscice >= n || preostaliSkoki < 0)
		return;
	
	t[indeksPloscice] = 1;
	
	rek(t, n, k1, k2, preostaliSkoki - 1, indeksPloscice + k1);
	rek(t, n, k1, k2, preostaliSkoki - 1, indeksPloscice - k1);
	rek(t, n, k1, k2, preostaliSkoki - 1, indeksPloscice + k2);
	rek(t, n, k1, k2, preostaliSkoki - 1, indeksPloscice - k2);
}

int main()
{
	int n, k1, k2, s;
	scanf("%d %d %d %d", &n, &k1, &k2, &s);
	
	int* t = calloc(n, sizeof(int));
	t[0] = 1;
	
	rek(t, n, k1, k2, s, 0);
	
	int stevilo = 0;
	for(int i = 0; i < n; i++)
		stevilo += t[i];
	
	printf("%d\n", stevilo);
	
	free(t);
    return 0;
}

