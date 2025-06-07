#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DOLZINA 1000

void razlike(FILE* prva, FILE* druga, FILE* izhod)
{
	int i = 1;
	
	char* vrstica1 = malloc(MAX_DOLZINA * sizeof(char));
	char* vrstica2 = malloc(MAX_DOLZINA * sizeof(char));
	
	while(i < 100)
	{
		
		char* ena = fgets(vrstica1, MAX_DOLZINA, prva);
		char* dva = fgets(vrstica2, MAX_DOLZINA, druga);
		
		if(ena == NULL || dva == NULL)
		{
			break;
		}
		
		if(strcmp(vrstica1, vrstica2) != 0)
		{
			fprintf(izhod, "%d\n", i);
		}
		
		i++;
	}
	free(vrstica1);
	free(vrstica2);
}

int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		printf("Premalo argumentov\n");
		exit(1);
	}
	
	FILE* prva = fopen(argv[1], "r");
	if(prva == NULL)
	{
		printf("Napaka pri odpiranju datoteke\n");
		exit(1);
	}

	FILE* druga = fopen(argv[2], "r");
	if(druga == NULL)
	{
		printf("Napaka pri odpiranju datoteke\n");
		fclose(prva);
		exit(1);
	}
	
	FILE* izhod = fopen(argv[3], "w");
	if(izhod == NULL)
	{
		printf("Napaka pri odpiranju datoteke\n");
		fclose(prva);
		fclose(druga);
		exit(1);
	}
	
	razlike(prva, druga, izhod);
	
	fclose(prva);
	fclose(druga);
	fclose(izhod);

    return 0;
}

