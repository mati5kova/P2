#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VELIKOST 201
#define OFFSET 100

/*
 * na vhodu so trojice y, x, dolzina stranice
 *
 * polje ima kordinate od -100 do 100, "shiftamo vse v desno"
 *   -> -100 = 0
 */


int main()
{
	int n; scanf("%d\n", &n);
	
	int** t = malloc(VELIKOST * sizeof(int*));
	for(int i = 0; i < VELIKOST; i++)
	{
		t[i] = calloc(VELIKOST, sizeof(int));
	}
	
	int* pokritve = calloc(n + 1, sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		int y, x, dolzina; scanf("%d %d %d\n", &y, &x, &dolzina);
		
		y += OFFSET;
		x += OFFSET;
		
		for(int vrstica = x; vrstica < x + dolzina; vrstica++)
		{
			//t[vrstica][y]++;
			
			for(int stolpec = y; stolpec < y + dolzina; stolpec++)
			{
				t[stolpec][vrstica]++;
			}
			
		}
		
		/* vmesni izpis polja po vsakem dodanem kvadratu
		for(int i = 0; i < VELIKOST; i++)
		{
			for(int j = 0; j < VELIKOST; j++)
			{
				printf("%d ", t[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
	}
	
	for(int i = 0; i < VELIKOST; i++)
		for(int j = 0; j < VELIKOST; j++)
			pokritve[t[i][j]]++;

	
	for(int i = 1; i < n + 1; i++)
		printf("%d\n", pokritve[i]);
	
	
	for(int i = 0; i < VELIKOST; i++)
		free(t[i]);
	free(t);
	free(pokritve);
	
	return 0;
}