#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Klub {
	char ime[21];
	int stClanov;
	char** imenaIgralcev;
} Klub;

Klub* izdelaj()
{
	Klub* novKlub = malloc(sizeof(Klub));
	
	scanf("%s", novKlub->ime);
	scanf("%d", &(novKlub->stClanov));
	
	novKlub->imenaIgralcev = malloc((novKlub->stClanov) * sizeof(char*));
	
	for(int i = 0; i < novKlub->stClanov; i++)
	{
		char* posameznoIme = malloc(21 * sizeof(char));
		scanf("%s", posameznoIme);
		(novKlub->imenaIgralcev)[i] = posameznoIme;
	}
	
	return novKlub;
}

int main()
{
	
	Klub* klub = izdelaj();
	
	printf("Ime kluba: %s\n", klub->ime);
	printf("Imena igralcev (%d): \n", klub->stClanov);
	
	for(int i = 0; i < klub->stClanov; i++)
	{
		printf("		    - %s\n", (klub->imenaIgralcev)[i]);
	}
	
	
	// cleanup
	for(int i = 0; i < klub->stClanov; i++)
	{
		free((klub->imenaIgralcev)[i]);
	}
	free(klub->imenaIgralcev);
	free(klub);
	
    return 0;
}

