#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int abs(int a)
{
	if(a > 0) return a;
	return 0 - a;
}

int razdaljaMedPoljema(int** t, int p, int q, int polje1, int polje2) // manhatanska razdalja
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	
	for(int i = 0; i < p; i++)
	{
		for(int j = 0; j < q; j++)
		{
			if(t[i][j] == polje1)
			{
				x1 = i;
				y1 = j;
			}
			if(t[i][j] == polje2)
			{
				x2 = i;
				y2 = j;
			}
		}
	}
	
	return abs(x2 - x1) + abs(y2 - y1);
}

int main()
{
	int p, q, d; scanf("%d %d %d\n", &p, &q, &d);
	
	int** t = malloc(p * sizeof(int*));
	for(int i = 0; i < p; i++)
	{
		t[i] = malloc(q * sizeof(int));
		
		for(int k = 0; k < q; k++)
			scanf("%d", &(t[i][k]));
	}	
	
	for(int i = 1; i < (p * q); i++)
	{		
		int porabljenoGorivoOdPrejsnjegaPolja = razdaljaMedPoljema(t, p, q, i, i - 1);
		//printf("%d->%d : %d\n", i - 1, i, porabljenoGorivoOdPrejsnjegaPolja);
		
		d -= porabljenoGorivoOdPrejsnjegaPolja;
		
		if(d < 0)
		{
			printf("%d\n", i - 1);
			break;
		}
	}
	
	
	for(int i = 0; i < p; i++)
		free(t[i]);
	free(t);
	
	return 0;
}