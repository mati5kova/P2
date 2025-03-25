#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ST_ELEMENTOV 10

void izpis(int a, int *pa)
{
	printf("a:[%d], pa:[%p], *pa:[%d], &pa:[%p]\n", a, (void*)pa, *pa, (void*)&pa);
}

/*
*	&*x   <==>   x
*	  enakovredno
*/

int main()
{
	
	int *pa;
	int a = 1000;
	pa = &a;
	
	printf("zacetno stanje:\n");
	izpis(a, pa);
	
	printf("a += 1\n");
	a += 1;
	izpis(a, pa);
	
	
	int *t = calloc(ST_ELEMENTOV, sizeof(int));
	int *prvi = &t[0];
	int *zadnji = &t[ST_ELEMENTOV - 1];
	
	printf("\n&t:[%p], *prvi:[%d], *zadnji:[%d]\n", (void*)&t, *prvi, *zadnji);
	
	printf("\nt[ST_ELEMENTOV - 1] = -1\n");
	t[ST_ELEMENTOV - 1] = -1;
	printf("&prvi:[%p], *prvi:[%d], *zadnji:[%d]\n", (void*)&prvi, *prvi, *zadnji);
	
	printf("\nprvi += 9:\n");
	prvi += 9;
	printf("&t:[%p], *prvi:[%d], *zadnji:[%d]\n", (void*)&prvi, *prvi, *zadnji);
	prvi -= 9;
	printf("reset: &t:[%p], *prvi:[%d], *zadnji:[%d]\n", (void*)&prvi, *prvi, *zadnji);
	
	for(int i = 0; i < ST_ELEMENTOV; i++)
	{
		t[i] = i;
	}
	
	printf("\nzadnji: %d, %p, naslov zadnjega elementa v t: [%p]\n", *zadnji, (void*)&zadnji, (void*)&t[ST_ELEMENTOV-1]);
	
	for(int i = 0; i < ST_ELEMENTOV - 1; i++)
	{
		printf("&prvi:[%p], *prvi:[%d], &*prvi:[%p]\n", (void*) &prvi, *prvi, (void*)&*prvi);
		prvi++;
	}
	printf("vrednost na koncu: %d, naslov zadnje vrednosti v t:[%p]\n", *prvi, (void*)&*prvi);
	
	free(t);
	return 0;
}