#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	int podatek;
	struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* ustvari(int podatek, Vozlisce* naslednje)
{
	Vozlisce* n = malloc(sizeof(Vozlisce));
	n->podatek = podatek;
	n->naslednje = naslednje;
	return n;
}

Vozlisce* zlij(Vozlisce* a, Vozlisce* b)
{
	if(a == NULL) return b;
	if(b == NULL) return a;
	
	Vozlisce* tempa = a;
	Vozlisce* tempb = b;
	Vozlisce* c = ustvari(0, NULL);
	Vozlisce* tempc = c;
	
	if(a->podatek < b->podatek)
	{
		c->podatek = a->podatek;
		c->naslednje = a->naslednje;
		tempa = a->naslednje;
	} else
	{
		c->podatek = b->podatek;
		c->naslednje = b->naslednje;
		tempb = b->naslednje;
	}
	
	while(tempa != NULL || tempb != NULL)
	{
		if(tempa == NULL)
		{
			tempc->naslednje = tempb;
			tempb = tempb->naslednje;
				printf("1\n");
		} else if(tempb == NULL)
		{
			tempc->naslednje = tempa;
			tempa = tempa->naslednje;
				printf("2\n");
		} else
		{
			// noben ni NULL
			if(tempa->podatek < tempb->podatek)
			{
				tempc->naslednje = tempa;
				tempa = tempa->naslednje;
				printf("3\n");
			} else
			{
				tempc->naslednje = tempb;
				tempb = tempb->naslednje;
				printf("4\n");
			}
		}
		tempc = tempc->naslednje;
	}
	
	return c;
}

void izpisi(Vozlisce* start)
{
	Vozlisce* temp = start;
	while(temp != NULL)
	{
		printf("%d -> ", temp->podatek);
		temp = temp->naslednje;
	}
	printf("\n");
}

int main()
{
	Vozlisce* _13 = ustvari(13, NULL);
	Vozlisce* _12 = ustvari(12, _13);
	Vozlisce* _8 = ustvari(8, _12);
	Vozlisce* _4 = ustvari(4, _8);
	Vozlisce* a = ustvari(3, _4);
	
	Vozlisce* _16 = ustvari(16, NULL);
	Vozlisce* _11 = ustvari(11, _16);
	Vozlisce* _10 = ustvari(10, _11);
	Vozlisce* b = ustvari(7, _10);

	izpisi(a);
	izpisi(b);

	Vozlisce* c = zlij(NULL, b);
	
	izpisi(c);

	free(_13);
	free(_12);
	free(_8);
	free(_4);
	free(a);
	
	free(_16);
	free(_11);	
	free(_10);
	free(b);
	
	if(c != a && c != b)
		free(c);

    return 0;
}





