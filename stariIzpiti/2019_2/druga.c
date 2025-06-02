#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 6

typedef struct Oseba Oseba;
struct Oseba { 	   // oseba s podanim imenom in starostjo
	char* ime; 	   // zaporedje do 20 črk angleške abecede
	int starost;
};

void izpisi(Oseba** osebe, int n)
{
	for(int i = 0; i < n; i++)
	{
		Oseba* curr = osebe[i];
		printf("{\"%s\", %d}\n", curr->ime, curr->starost);
	}
}

bool jeUrejeno(Oseba** osebe, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		Oseba* curr = osebe[i];
		Oseba* next = osebe[i + 1];
		
		if(strcmp(curr->ime, next->ime) > 0)
			return false;
	}
	return true;
}

void uredi(Oseba** osebe, int n)
{
	while(!jeUrejeno(osebe, n))
	{
		for(int i = 0; i < n - 1; i++)
		{
			Oseba* curr = osebe[i];
			Oseba* next = osebe[i + 1];
			
			if(strcmp(curr->ime, next->ime) > 0)
			{
				Oseba* temp = curr;
				osebe[i] = osebe[i + 1];
				osebe[i + 1] = temp;
			}
			
			printf("->\n");
			izpisi(osebe, n);
		}
	}
}

int main()
{
	char** imena = malloc(N * sizeof(char*));
	for(int i = 0; i < N; i++)
	{
		imena[i] = malloc(21 * sizeof(char));
	}
	
	strcpy(imena[0], "Bojan");
    strcpy(imena[1], "Ana");
    strcpy(imena[2], "Bojan");
    strcpy(imena[3], "Cene");
    strcpy(imena[4], "Bojan");
    strcpy(imena[5], "Ana");
	
	int starosti[N] = {30, 25, 40, 15, 20, 20};
	
	Oseba** osebe = malloc(N * sizeof(Oseba*));
	
	for(int i = 0; i < N; i++)
	{
		osebe[i] = malloc(sizeof(Oseba));
		osebe[i]->ime = imena[i];
		osebe[i]->starost = starosti[i];
	}

	izpisi(osebe, N);
	
	uredi(osebe, N);
	
	printf("\n");
	izpisi(osebe, N);
	
	for(int i = 0; i < N; i++)
	{
		free(osebe[i]);
		free(imena[i]);
	}
	free(osebe);
	free(imena);

    return 0;
}

