#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	int podatek;
	struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* obrni(Vozlisce* zacetek)
{
	if(zacetek == NULL || zacetek->naslednje == NULL)
		return zacetek;
	
	Vozlisce* prejsnje = NULL;
	Vozlisce* temp = zacetek;
	while(temp != NULL)
	{
		Vozlisce* originalnoNaslednje = temp->naslednje;
		temp->naslednje = prejsnje;
		if(originalnoNaslednje == NULL)
		{
			return temp;
		}
		prejsnje = temp;
		temp = originalnoNaslednje;
	}
	return temp;
}

void izpisi(Vozlisce* zacetek)
{
	Vozlisce* temp = zacetek;
	while(temp != NULL)
	{
		printf("-> %d ", temp->podatek);
		temp = temp->naslednje;
	}
	
	printf("\n");
}

Vozlisce* ustvariVozlisce(int podatek, Vozlisce* naslednje)
{
	Vozlisce* novo = malloc(sizeof(Vozlisce));
	novo->podatek = podatek;
	novo->naslednje = naslednje;
	return novo;
}

void pocisti(Vozlisce* zacetek)
{
	if(zacetek->naslednje == NULL)
	{
		free(zacetek);
	} else 
	{
		pocisti(zacetek->naslednje);
		free(zacetek);
	}
}

int main()
{
	Vozlisce* _3 = ustvariVozlisce(3, NULL);
	Vozlisce* _9 = ustvariVozlisce(9, _3);
	Vozlisce* _6 = ustvariVozlisce(6, _9);
	Vozlisce* _2 = ustvariVozlisce(2, _6);
	Vozlisce* zacetek = ustvariVozlisce(7, _2);
	
	izpisi(zacetek);

	Vozlisce* rezultat = obrni(zacetek);

	izpisi(rezultat);

	pocisti(rezultat);
	
    return 0;
}

