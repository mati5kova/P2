#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* f;
	
	f = fopen(argv[1], "r");
	if(f == NULL)
	{
		printf("Napaka pri odpiranju datoteke\n");
		exit(1);
	}
	
	char* t1 = malloc(1000000 * sizeof(char));
	char* t2 = malloc(1000000 * sizeof(char));
	int currMaxLen = 0;
	
	while(1)
	{
		char* c = fgets(t2, 1000000, f);
		if(c == NULL)
			break;
		
		int dolzinaTrenutneVrstice = strlen(t2);
		if(dolzinaTrenutneVrstice > currMaxLen)
		{
			currMaxLen = dolzinaTrenutneVrstice;
			strcpy(t1, t2);
		}
	}
	
	int rez = fclose(f);
	if(rez != 0)
	{
		printf("Napaka pri zapiranju datoteke\n");
		exit(1);
	}
	
	f = fopen(argv[2], "w");
	if(f == NULL)
	{
		printf("Napaka pri odpiranju datoteke\n");
		exit(1);
	}
	fputs(t1, f);
	
	rez = fclose(f);
	if(rez != 0)
	{
		printf("Napaka pri zapiranju datoteke\n");
		exit(1);
	}
	
	free(t1);
	free(t2);
	return 0;
}