#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	char vhod[21];
	char izhod[21];
	char crka;
	
	scanf("%s\n%s\n%c", vhod, izhod, &crka);
	
	FILE* in = fopen(vhod, "r");
	if(in == NULL)
	{
		printf("Napaka pri branju datoteke %s\n", vhod);
		exit(1);
	}
	
	char* last_ocurr = malloc(1002 * sizeof(char));
	
	while(1)
	{
		char* buffer = malloc(1002 * sizeof(char));
		char* r = fgets(buffer, 1002, in);
		if(r == NULL)
		{
			break;
		}
		
		for(int i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] == crka)
			{
				strcpy(last_ocurr, buffer);
				break;
			}
		}
		
		free(buffer);
	}
	
	
	FILE* out = fopen(izhod, "w");
	if(out == NULL)
	{
		printf("Napaka pri odpiranju datoteke %s\n", izhod);
		exit(1);
	}
	
	fprintf(out, "%s", last_ocurr);
	
	fclose(out);
	fclose(in);
	free(last_ocurr);
    return 0;
}

