#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	struct _Vozlisce* naslednje;
} Vozlisce;

bool neKazeNaZacetekCikla(Vozlisce** t, Vozlisce* zacetek, int stVozlisc)
{
	for(int i = 0; i < stVozlisc; i++)
	{
		if(zacetek == t[i])
			return false;
	}
	
	return true;
}

int dolzinaCikla(Vozlisce* zacetek)
{
	Vozlisce** t = malloc(1000 * sizeof(Vozlisce*));
	int stVozlisc = 0;
	Vozlisce* temp = zacetek;
	
	while(neKazeNaZacetekCikla(t, temp, stVozlisc))
	{
		t[stVozlisc++] = temp;
		temp = temp->naslednje;
	}
	
	for(int i = stVozlisc - 1; i >= 0; i--)
	{
		if(t[i] == temp)
		{
			free(t);
			return stVozlisc-i;
		}
	}
	
	free(t);
	return 0;
}

int main()
{
	Vozlisce* zacetek = malloc(sizeof(Vozlisce));
	Vozlisce* b = malloc(sizeof(Vozlisce));
	Vozlisce* c = malloc(sizeof(Vozlisce));
	Vozlisce* d = malloc(sizeof(Vozlisce));
	Vozlisce* e = malloc(sizeof(Vozlisce));
	Vozlisce* f = malloc(sizeof(Vozlisce));
	Vozlisce* g = malloc(sizeof(Vozlisce));
	Vozlisce* h = malloc(sizeof(Vozlisce));
	Vozlisce* i = malloc(sizeof(Vozlisce));
	
	zacetek->naslednje = b;
	b->naslednje = c;
	c->naslednje = d;
	d->naslednje = e;
	e->naslednje = f;
	f->naslednje = g;
	g->naslednje = h;
	h->naslednje = i;
	i->naslednje = d;
	
	printf("%d\n", dolzinaCikla(zacetek));
	
	free(zacetek);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	free(g);
	free(h);
	free(i);
    return 0;
}

