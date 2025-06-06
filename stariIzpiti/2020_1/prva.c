#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DOLZINA 1001

void obrni(FILE* vhod, FILE* izhod)
{
	char** buffer = malloc(MAX_DOLZINA * sizeof(char*));
	for(int i = 0; i < MAX_DOLZINA; i++)
		buffer[i] = malloc(MAX_DOLZINA * sizeof(char));
	
	int stVrstic = 0;
	
	while((fgets(buffer[stVrstic++], MAX_DOLZINA, vhod)) != NULL) {}
	
	for(int i = stVrstic - 1; i >= 0; i--)
	{
		fprintf(izhod, "%s", buffer[i]);
		if(buffer[i][strlen(buffer[i]) - 1] != '\n' && i != stVrstic - 1)
		{
			fprintf(izhod, "\n");
		}
	}
	
	for(int i = 0; i < MAX_DOLZINA; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
}

int main(int argc, char* argv[])
{
	FILE* vhod = fopen(argv[1], "r");
	if(vhod == NULL)
	{
		printf("Napaka pri branju datoteke %s\n", argv[1]);
		exit(1);
	}
	
	FILE* izhod = fopen(argv[2], "w");
	if(izhod == NULL)
	{
		printf("Napaka pri odpiranju datoteke %s\n", argv[2]);
		exit(1);
	}
	
	obrni(vhod, izhod);
	
	fclose(vhod);
	fclose(izhod);
    return 0;
}

