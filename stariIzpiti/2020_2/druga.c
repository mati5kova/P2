#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	int podatek;
	struct _Vozlisce* naslednje;
} Vozlisce;

void izpisi(Vozlisce* zac)
{
	Vozlisce* temp = zac;
	while(temp != NULL)
	{
		printf("%d -> ", temp->podatek);
		temp = temp->naslednje;
	}
	printf("\n");
}

Vozlisce* ustvari(int podatek, Vozlisce* naslednje)
{
	Vozlisce* n = malloc(sizeof(Vozlisce));
	n->podatek = podatek;
	n->naslednje = naslednje;
	
	return n;
}

Vozlisce* izloci(Vozlisce* zac, Vozlisce* v)
{
	if(zac->podatek == v->podatek && zac->naslednje == v->naslednje)
		return zac->naslednje;

	Vozlisce* temp = zac;

	while(temp != NULL)
	{
		if(temp->naslednje == v && temp->naslednje->podatek == v->podatek)
		{
			temp->naslednje = temp->naslednje->naslednje;
			free(v);
		}
		temp = temp->naslednje;
	}
	
	return zac;
}

void cleanup(Vozlisce* zac)
{
	if(zac == NULL)
		return;
	cleanup(zac->naslednje);
	free(zac);
}

int main()
{
	Vozlisce* _5 = ustvari(5, NULL);
	Vozlisce* _4 = ustvari(4, _5);
	Vozlisce* _3 = ustvari(3, _4);
	Vozlisce* _2 = ustvari(2, _3);
	Vozlisce* _1 = ustvari(1, _2);
	Vozlisce* _0 = ustvari(0, _1);
	
	izpisi(_0);
	
	izloci(_0, _3);
	
	izpisi(_0);
	
	cleanup(_0);
    return 0;
}

