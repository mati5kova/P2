#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce Vozlisce;
struct _Vozlisce {
	int vsebina;     // »vsebina« vozlišča
	Vozlisce* desno; // kazalec na desnega soseda ( NULL v zadnjem stolpcu)
	Vozlisce* dol;   // kazalec na spodnjega soseda ( NULL v zadnji vrstici)
};

int sirina(Vozlisce* start)
{
	if(start == NULL)
		return 0;
	return 1 + sirina(start->desno);
}

int visina(Vozlisce* start)
{
	if(start == NULL)
		return 0;
	return 1 + visina(start->dol);
}

Vozlisce* ustvari(int vsebina, Vozlisce* desno)
{
	Vozlisce* novo = malloc(sizeof(Vozlisce));
	novo->vsebina = vsebina;
	novo->desno = desno;
	novo->dol = NULL;
	
	return novo;
}


Vozlisce* diagonala(Vozlisce* start, int* vsota)
{
	if(start == NULL)
	{
		*vsota = 0;
		return NULL;
	}
	int* t = malloc(100 * sizeof(int));
	int st = 0;
	
	int w, h;
	w = sirina(start);
	h = visina(start);
	
	int offset = 0;
	Vozlisce* levoZgoraj = start;
	
	for(int vrstica = 0; vrstica < h; vrstica++)
	{
		Vozlisce* zacetekVrstice = levoZgoraj;
		for(int stolpec = 0; stolpec < w - offset; stolpec++)
		{
			if(stolpec == w - offset - 1)
			{
				// smo na elementu diagonale
				t[st++] = zacetekVrstice->vsebina;
			}
			zacetekVrstice = zacetekVrstice->desno;
		}
		
		offset++;// v naslednji vrstici gremo do enega elementa manj v desno
		levoZgoraj = levoZgoraj->dol;
	}
	
	Vozlisce* nov_zacetek = ustvari(t[0], NULL);
	*vsota = t[0];
	Vozlisce* temp = nov_zacetek;
	for(int i = 1; i < st; i++)
	{
		*vsota += t[i];
		temp->desno = ustvari(t[i], NULL);
		temp = temp->desno;
	}
	
	
	free(t);
	return nov_zacetek;
}

/*
int main()
{
    return 0;
}
*/
