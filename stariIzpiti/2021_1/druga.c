#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	struct _Vozlisce* n; // naslednje vozlišče v verigi oz. NULL, če ga ni
} Vozlisce;

long long int dolzina(Vozlisce* start)
{
	Vozlisce* temp = start;
	long long int counter = 0;
	while(temp != NULL)
	{
		counter++;
		temp = temp->n;
	}
	return counter;
}


Vozlisce* sticisce(Vozlisce* a, Vozlisce* b)
{
	Vozlisce* tempA = a;
	Vozlisce* tempB = b;
	long long int dolzinaA = dolzina(a);
	long long int dolzinaB = dolzina(b);

	if(dolzinaA >= dolzinaB)
	{
		// premaknemo a na enako dolzino kot je b
		for(long long int i = 0; i < (dolzinaA - dolzinaB); i++)
		{
			tempA = tempA->n;
		}
	} else
	{
		// premaknemo b  -||-
		for(long long int i = 0; i < (dolzinaB - dolzinaA); i++)
		{
			tempB = tempB->n;
		}
	}

	while(tempA != NULL && tempB != NULL)
	{
		if(tempA == tempB)
			return tempA;
		
		tempA = tempA->n;
		tempB = tempB->n;
	}

	return NULL;
}



int main()
{
	Vozlisce* a1 = malloc(sizeof(Vozlisce));
    Vozlisce* a2 = malloc(sizeof(Vozlisce));
    Vozlisce* b1 = malloc(sizeof(Vozlisce));
    Vozlisce* c1 = malloc(sizeof(Vozlisce));  // sticisce
    Vozlisce* c2 = malloc(sizeof(Vozlisce));
    Vozlisce* c3 = malloc(sizeof(Vozlisce));
    Vozlisce* c4 = malloc(sizeof(Vozlisce));


    a1->n = a2;
    a2->n = c1;

    b1->n = c1;

	// skupni del
    c1->n = c2;
    c2->n = c3;
    c3->n = c4;
    c4->n = NULL;

    Vozlisce* najdeno = sticisce(a1, b1);

    if (najdeno == c1) {
        printf("Pravilno! stičišče na nodu %p\n", (void*)najdeno);
    } else {
        printf("Napaka\n");
    }

	// cleanup
    free(a1);
    free(a2);
    free(b1);
    free(c1);
    free(c2);
    free(c3);
    free(c4);
    return 0;
}
