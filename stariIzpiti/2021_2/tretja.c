#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int min(int a, int b) { return a < b ? a : b; }

typedef struct _Vozlisce {
	struct _Vozlisce* n; 	// kazalec na naslednje vozlišče v verigi oz. NULL, če ga ni
	struct _Vozlisce* r; 	// kazalec na poljubno vozlišče v verigi ali NULL
} Vozlisce;


// shranjuje naslove vseh (max. 20) vozlišč
// -> za potrebe pregledovanja ali je skok nazaj in bo prišlo do infinte loop-a
Vozlisce* t[20] = {NULL}; 


Vozlisce* ustvari(Vozlisce* n, Vozlisce* r)
{
	Vozlisce* novo = malloc(sizeof(Vozlisce));
	novo->n = n;
	novo->r = r;
	return novo;
}

bool niSkokNazaj(Vozlisce* izvor, Vozlisce* cilj)
{
	Vozlisce* temp = t[0];
	bool ciljZeNajden = false;
	bool izvorZeNajden = false;
	while(temp != NULL)
	{
		if(temp == cilj)
			ciljZeNajden = true;
		if(temp == izvor)
			izvorZeNajden = true;
		
		if(ciljZeNajden && !izvorZeNajden)
			return false;
		
		temp = temp->n;
	}
	return true;
}

int najkrajsaPot(Vozlisce* izvor, Vozlisce* cilj)
{	
	// napolni tabelo naslovov vozlisc ce le ta se ne obstaja
	if(t[0] == NULL)
	{
		Vozlisce* temp = izvor;
		int i = 0;
		while(temp != NULL)
		{
			t[i++] = temp;
			temp = temp->n;
		}
	}

	if(izvor == cilj)
	{
		// smo na koncu
		return 0;
	}
	
	// gremo samo naprej
	int a = 1 + najkrajsaPot(izvor->n, cilj);
	int b = a;
	
	// gremo dol če:
	// - ne gremo sami vaje
	// - ne gremo v NULL
	// - ne gremo nazaj po seznamu
	if(izvor->r != izvor && izvor->r != NULL && niSkokNazaj(izvor, izvor->r)) // da ne gremo samo vase
	{
		b = 1 + najkrajsaPot(izvor->r, cilj);		
	}
	
	return min(a, b);
}

void cleanup(Vozlisce* start)
{
	if(start == NULL)
	{
		return;
	}
	cleanup(start->n);
	free(start);
}

int main()
{
	Vozlisce* cilj = ustvari(NULL, NULL);
	Vozlisce* _9 = ustvari(cilj, NULL);
	Vozlisce* _8 = ustvari(_9, cilj);
	Vozlisce* _7 = ustvari(_8, NULL);
	Vozlisce* _6 = ustvari(_7, NULL);
	Vozlisce* _5 = ustvari(_6, _8);
	Vozlisce* _4 = ustvari(_5, _6);
	Vozlisce* _3 = ustvari(_4, NULL);
	_6->r = _3;
	Vozlisce* _2 = ustvari(_3, NULL);
	_2->r = _2;
	Vozlisce* izvor = ustvari(_2, NULL);

	
	printf("izvor %p\n", izvor);
	printf("_2 %p\n", _2);
	printf("_3 %p\n", _3);
	printf("_4 %p\n", _4);
	printf("_5 %p\n", _5);
	printf("_6 %p\n", _6);
	printf("_7 %p\n", _7);
	printf("_8 %p\n", _8);
	printf("_9 %p\n", _9);
	printf("cilj %p\n", cilj);
	
	int pot = najkrajsaPot(izvor, cilj);
	printf("\nNajkrajša pot: [%d]\n", pot);
	
	cleanup(izvor);

    return 0;
}

