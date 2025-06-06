#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void izpis(int* t, int stEl)
{	
	if(stEl == 0)
	{
		printf("{}\n");
		return;
	}
	printf("{");
	for(int i = 0; i < stEl; i++)
	{
		printf("%d", t[i]);
		if(i != stEl - 1)
			printf(", ");
	}
	printf("}\n");
}

void rek(int* t, int n, int* podmnozica, int stEl, int indeks)
{	
	if(indeks == n)
	{
		// izpis
		izpis(podmnozica, stEl);
		return;
	}
	
	// ne vzamemo trenutnega elementa
	rek(t, n, podmnozica, stEl, indeks + 1);
	
	// vzamemo trenutni element
	podmnozica[stEl] = t[indeks];
	rek(t, n, podmnozica, stEl + 1, indeks + 1);
	
	
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int t[20];
	int podmnozica[20];
	for(int i = 0; i < n; i++)
		scanf("%d", &(t[i]));	
	
	rek(t, n, podmnozica, 0, 0);
	
    return 0;
}

