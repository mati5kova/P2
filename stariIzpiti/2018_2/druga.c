#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {  // vozlišče povezanega seznama
	int podatek; 			// podatek v vozlišču
	struct _Vozlisce* n;    // kazalec na naslednika ( NULL, če ga ni)
	struct _Vozlisce* nn;   // kazalec na naslednika naslednika ( NULL, če ga ni)
} Vozlisce;

Vozlisce* ustvariVozlisce(int element, Vozlisce* naslednje, Vozlisce* nanaslednje)
{
	Vozlisce* novo = (Vozlisce*) malloc(sizeof(Vozlisce));
	novo->podatek = element;
	novo->n = naslednje;
	novo->nn = nanaslednje;
	return novo;
}

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element)
{
	Vozlisce* stariZacetek = zacetek;
	
	if(zacetek->n == NULL || zacetek->podatek > element)
	{
		if(zacetek == NULL || zacetek->podatek > element)
		{
			return ustvariVozlisce(element, zacetek, NULL);
		} else
		{
			Vozlisce* novo = ustvariVozlisce(element, NULL, NULL);
			zacetek->n = novo;
			zacetek->nn = NULL;
			return zacetek;
		}
	}
	Vozlisce* prejsnje = NULL;
	while(zacetek->n != NULL)
	{
		if(zacetek->n == NULL)
		{
			Vozlisce* novo = ustvariVozlisce(element, NULL, NULL);
			zacetek->n = novo;
			prejsnje->nn = novo;
			return stariZacetek;
		}
		if(zacetek->n->podatek > element)
		{
			//zacetek kaze na 30, zacetek->n pa na 50
			
			Vozlisce* novo = ustvariVozlisce(element, zacetek->n, zacetek->nn);
			zacetek->nn = zacetek->n;
			zacetek->n = novo;
			return stariZacetek;
		} else
		{
			prejsnje = zacetek;
			zacetek = zacetek->n;
		}
	}
	if(zacetek->n == NULL)
		{
			Vozlisce* novo = ustvariVozlisce(element, NULL, NULL);
			zacetek->n = novo;
			prejsnje->nn = novo;
			return stariZacetek;
		}
	
	
}

void izpisi(Vozlisce* temp)
{
	while(temp->n != NULL)
	{
		printf("%d -> ", temp->podatek);
		temp = temp->n;
	}
	printf("%d\n", temp->podatek);
}

void sprosti(Vozlisce* zacetek) {
    while (zacetek != NULL) {
        Vozlisce* naslednje = zacetek->n;
        free(zacetek);
        zacetek = naslednje;
    }
}


int main() 
{
	Vozlisce* _70 = ustvariVozlisce(70, NULL, NULL);
	Vozlisce* _50 = ustvariVozlisce(50, _70, NULL);
	Vozlisce* _30 = ustvariVozlisce(30, _50, _70);
	Vozlisce* _20 = ustvariVozlisce(20, _30, _50);
	
	Vozlisce* novZacetek = vstaviUrejeno(_20, 40);
	
	Vozlisce* temp = novZacetek;
	izpisi(temp);
	
	novZacetek = vstaviUrejeno(_20, 10);
	temp = novZacetek;
	izpisi(temp);
	
	novZacetek = vstaviUrejeno(_20, 80);
	temp = novZacetek;
	izpisi(temp);
	
	sprosti(novZacetek);
	
	Vozlisce* _NULL_V = ustvariVozlisce(20, NULL, NULL);
	novZacetek = vstaviUrejeno(_NULL_V, 80);
	temp = novZacetek;
	izpisi(temp);
	
	novZacetek = vstaviUrejeno(_NULL_V, 5);
	temp = novZacetek;
	izpisi(temp);
	
	
	sprosti(novZacetek);

    return 0;
}

