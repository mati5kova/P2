#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	int* vTabelo; 				 // kazalec na nek element tabele t
	struct _Vozlisce* naslednje; // kazalec na naslednje vozlišče seznama
} Vozlisce;

int potenciraj2(int osnova, int potenca)
{
	if(potenca == 0)
		return 1;
	
	return (osnova << (potenca - 1));
}

Vozlisce* ustvari(int* vTabelo, Vozlisce* naslednje)
{
	Vozlisce* novo = malloc(sizeof(Vozlisce));
	novo->vTabelo = vTabelo;
	novo->naslednje = naslednje;
	return novo;
}

// d - dolzina tabele t
// n - dolzina novo ustvarjene tabele kazalcev
Vozlisce** tabelaSeznamov(int* t, int d, int n)
{
	Vozlisce** rezultat = malloc(n * sizeof(Vozlisce*));
	
	for(int i = 0; i < n; i++)
	{
		int potenca = potenciraj2(2, i);
		
		Vozlisce* prejsnjeVVrsti = NULL;
		
		for(int k = potenca - 1; k < d; k += potenca)
		{
			Vozlisce* n = NULL;
			if(prejsnjeVVrsti == NULL)
			{
				
				n = ustvari(&(t[k]), NULL);
				rezultat[i] = n;
			} else
			{
				prejsnjeVVrsti->naslednje = ustvari(&(t[k]), NULL);
				n = prejsnjeVVrsti->naslednje;
			}
			prejsnjeVVrsti = n;
		}
	}
	
	return rezultat;
}

void izpisi(Vozlisce** tabela, int n)
{
	for(int i = 0; i < n; i++)
	{
		Vozlisce* zacetek = tabela[i];
		Vozlisce* temp = zacetek;
		
		while(temp != NULL)
		{
			printf("%d, ", *(temp->vTabelo));
			temp = temp->naslednje;
		}
		printf("\n");
	}
}

void cleanupVrsta(Vozlisce* zacetek)
{
	if(zacetek == NULL)
		return;
	cleanupVrsta(zacetek->naslednje);
	free(zacetek);
}

int main()
{
	int t[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int d = sizeof(t)/sizeof(t[0]);
	int n = 4;
	
	Vozlisce** tabela = tabelaSeznamov(t, d, n);
	izpisi(tabela, n);
	
	for(int i = 0; i < n; i++)
	{
		cleanupVrsta(tabela[i]);
	}
	
	free(tabela);
    return 0;
}

