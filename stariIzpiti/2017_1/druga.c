#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
 * ideja je da za vsako novo skatlo v vzvratnem vrstnem redu iščemo na katerem kupu
 * in na kateri poziciji je, hkrati štejemo število od -1 različnih škatel ki jih na
 * tistem kupu srečamo in s tem vemo koliko jih moramo premakniti da pridemo do iskane
 *
 * namesto da že odstranjene zamenjamo z -1 bi jih lahko popolnoma odstranili in škatle nad iskano
 * premaknili navzdol ampak je to nepotrebna kompleksnost
 */

int main()
{
	int n, k, b; scanf("%d %d %d\n", &n, &k, &b);
	
	int** t = malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++)
	{
		t[i] = malloc(k * sizeof(int));
		for(int j = 0; j < k; j++)
		{
			t[i][j] = j + i*k;
		}
	}
	
	int steviloPremikov = 0;
		
	for(int i = 0; i < b; i++)
	{
		int skatla; scanf("%d", &skatla);
		bool najdeno = false;
		
		for(int stolpec = n - 1; stolpec >= 0 && !najdeno; stolpec--)
		{
			int stSkatelNadIskano = 0;
			for(int vrstica = k - 1; vrstica >= 0; vrstica--)
			{				
				if(t[stolpec][vrstica] != skatla && t[stolpec][vrstica] != -1)
					stSkatelNadIskano++;
				if(t[stolpec][vrstica] == skatla)
				{
					najdeno = true;
					
					steviloPremikov += stSkatelNadIskano;
					
					// odstrani iskano skatlo (zamenjaj jo z -1)
					t[stolpec][vrstica] = -1;
					break;
				}
			}
		}
	}
	
	// izpis koncnega stanja kupov skatel
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}
	
	printf("----------\nrezultat: ");
	printf("%d\n", steviloPremikov);
	
	for(int i = 0; i < n; i++)
	{
		free(t[i]);
	}
	free(t);
	
	return 0;
}