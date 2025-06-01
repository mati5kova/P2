#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	int podatek;
	struct _Vozlisce* naslednje; // kazalec na naslednje ( NULL, če ga ni)
} Vozlisce;


Vozlisce* ustvariNovo(int podatek, Vozlisce* naslednje)
{
	Vozlisce* novo = (Vozlisce*) malloc(sizeof(Vozlisce));
	novo->podatek = podatek;
	novo->naslednje = naslednje;
	return novo;
}

void izpisi(Vozlisce* zacetek)
{
	while(zacetek->naslednje != NULL)
	{
		printf("%d -> ", zacetek->podatek);
		zacetek = zacetek->naslednje;
	}
	printf("%d\n", zacetek->podatek);
}

Vozlisce* odstrani(Vozlisce* osnova, Vozlisce* indeksi)
{
	Vozlisce* tempOsnova = osnova;
	Vozlisce* tempIndeksi = indeksi;
	
	
	int currI = 0;
	Vozlisce* prejsnje = NULL;
	while(tempOsnova != NULL && tempIndeksi != NULL)
	{
		//printf("tempOsnova.podatek: %d   ", tempOsnova->podatek)
		//printf("tempIndeksi.podatek: %d\n", tempIndeksi->podatek);
		//izpisi(osnova);
		
		if(tempIndeksi->podatek == currI)
		{
			if(tempOsnova->naslednje == NULL)
			{
				free(tempOsnova);
				prejsnje->naslednje = NULL;
			} else if(currI == 0)
			{
				Vozlisce* n = tempOsnova->naslednje;
				free(tempOsnova);
				tempOsnova = n;
				osnova = n;
			} else
			{
				// smo na elemenu za odstranit
				prejsnje->naslednje = tempOsnova->naslednje;
				free(tempOsnova);
				tempOsnova = prejsnje->naslednje;
			}			
			// premaknemo tempIndeksi na naslednje indeksi
			tempIndeksi = tempIndeksi->naslednje;
		} else
		{
			prejsnje = tempOsnova;
			tempOsnova = tempOsnova->naslednje;
		}
		
		currI++;
	}
	
	return osnova;
}

int main() 
{
	Vozlisce* _50 = ustvariNovo(50, NULL);
	Vozlisce* _40 = ustvariNovo(40, _50);
	Vozlisce* _60 = ustvariNovo(60, _40);
	Vozlisce* _30 = ustvariNovo(30, _60);
	Vozlisce* osnova = ustvariNovo(70, _30);
	
	izpisi(osnova);
	
	
	Vozlisce* _4 = ustvariNovo(4, NULL);
	Vozlisce* _2 = ustvariNovo(2, _4);
	Vozlisce* indeksi = ustvariNovo(1, _2);
	
	Vozlisce* novaOsnova = odstrani(osnova, indeksi);
	izpisi(novaOsnova);
	
	
	indeksi = ustvariNovo(0, NULL);
	novaOsnova = odstrani(novaOsnova, indeksi);
	izpisi(novaOsnova);
	
    return 0;
}

