#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int preslikavaKorakaVNedovoljenoSmer[] = {2, 3, 0, 1};
int preslikavaKorakaVDodatekXKordinate[] = {-1, 0, 1, 0};
int preslikavaKorakaVDodatekYKordinate[] = {0, -1, 0, 1};

void izpisiArr(int* t, int st)
{
	for(int i = 0; i < st; i++)
	{
		printf("%d", t[i]);
	}
	printf("\n");
}

void rek(int*** t, int m, int n, int* koraki, int stKorakov, int xKordinata, int yKordinata, int nedovoljenaSmer)
{
	if(xKordinata < 0 || xKordinata >= n || yKordinata < 0 || yKordinata >= m)
		return;
	
	if(xKordinata == n - 1 && yKordinata == m - 1)
	{
		izpisiArr(koraki, stKorakov);
	}
	
	int* trenutnaCelica = t[yKordinata][xKordinata];
	
	// pregledamo za vse 4 stene v katero smer gremo lahko
	for(int i = 0; i < 4; i++)
	{
		int stena = trenutnaCelica[i];
		if(stena == 1 || i == nedovoljenaSmer) continue;
		
		//printf("i: %d -> \n", i);
		//izpisiArr(trenutnaCelica, 4);
		
		koraki[stKorakov] = i;
		rek(t, m, n, koraki, stKorakov + 1, xKordinata + preslikavaKorakaVDodatekXKordinate[i], yKordinata + preslikavaKorakaVDodatekYKordinate[i], preslikavaKorakaVNedovoljenoSmer[i]);
	}
	
}

int main()
{
	int m, n;
	scanf("%d %d\n", &m, &n);
	
	int*** t = malloc(m * sizeof(int**));
	for(int i = 0; i < m; i++)
	{
		t[i] = malloc(n * sizeof(int*));
		
		for(int k = 0; k < n; k++)
		{
			t[i][k] = malloc(4 * sizeof(int));
			
			for(int g = 0; g < 4; g++)
			{
				t[i][k][g] = getchar() - '0';
			}
			getchar(); // presledek / \n
		}
	}
	
	int* koraki = malloc(m*n*sizeof(int));
	
	
	rek(t, m, n, koraki, 0, 0, 0, 0);
	
	
	for(int i = 0; i < m; i++)
	{
		for(int k = 0; k < n; k++)
		{
			free(t[i][k]);
		}
		free(t[i]);
	}
	free(t);
	free(koraki);
	
    return 0;
}

