#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	int el;
	struct _Vozlisce* next;
} Vozlisce;

void izpis(Vozlisce* zacetek)
{
	while(zacetek != NULL)
	{
		printf("%d", zacetek->el);
		if(zacetek->next != NULL)
			printf(" -> ");
	
		zacetek = zacetek->next;
	}
	printf("\n");
}

Vozlisce* ustvari(int el)
{
	Vozlisce* v = malloc(sizeof(Vozlisce));
	v->el = el;
	v->next = NULL;
	return v;
}

Vozlisce* prepisi(int* t)
{
	if(t == NULL || t[0] == 0)
		return NULL;
	
	int i = 0;
	Vozlisce* nov_zacetek = ustvari(t[i]);
	Vozlisce* temp = nov_zacetek;
	
	while(1)
	{
		if(t[i + 1] == 0)
		{
			return nov_zacetek;
		}
		
		temp->next = ustvari(t[i + 1]);
		temp = temp->next;
		i++;
	}
	
	
}

void cleanup(Vozlisce* zacetek)
{
	if(zacetek == NULL)
		return;
	
	cleanup(zacetek->next);
	free(zacetek);
}

int main()
{
	int t[] = {1, 2, 3, 5, 4 ,77, 9, 6, 312, 999, 0};

	Vozlisce* og = prepisi(t);
	izpis(og);

    return 0;
}

