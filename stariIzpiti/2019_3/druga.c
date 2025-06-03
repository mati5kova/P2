#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int n;
	char* t = malloc((n + 1) * sizeof(char));
	
	scanf("%d\n%s\n", &n, t);
	
	int maxVisina = 0;
	int trenutnaVisina = 0;
	for(int i = 0; i < n; i++)
	{
		if(t[i] == 'G')
		{
			trenutnaVisina += 1;
		} else if(t[i] == 'D')
		{
			trenutnaVisina -= 1;
		}
		maxVisina = max(maxVisina, trenutnaVisina);
	}
	
	int offsetX = 0;
	int offsetY = maxVisina - 1;
	int** hrib = malloc(maxVisina * sizeof(int*));
	for(int i = 0; i < maxVisina; i++)
		hrib[i] = calloc(n, sizeof(int));
	
	char prejsnji = t[0];
	for(int i = 0; i < n; i++)
	{
		if(t[i] == 'G')
		{
			if(prejsnji == 'G' && i != 0)
				offsetY -= 1;
			hrib[offsetY][offsetX] = 1;
		} else if(t[i] == 'D')
		{
			if(prejsnji == 'D')
				offsetY += 1;
			hrib[offsetY][offsetX] = 2;
		}
		prejsnji = t[i];
		offsetX++;
	}
	
	for(int i = 0; i < maxVisina; i++)
	{
		for(int k = 0; k < n; k++)
		{
			if(hrib[i][k] == 0)
				putchar('.');
			if(hrib[i][k] == 1)
				putchar('/');
			if(hrib[i][k] == 2)
				putchar('\\');
		}
		putchar('\n');
	}
	
	for(int i = 0; i < maxVisina; i++)
		free(hrib[i]);
	free(hrib);
	
	free(t);
    return 0;
}

