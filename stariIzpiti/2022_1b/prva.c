#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXFON 31
typedef struct {
	char* ime;
	char telefon[MAXFON]; // telefonska številka
} Oseba;

char tempfon[MAXFON];

void vstaviPredpono(char* predpona, Oseba** osebe, int stOseb)
{
	int lenPredpona = strlen(predpona);
	
	for(int i = 0; i < stOseb; i++)
	{
		Oseba* oseba = osebe[i];
		strcpy(&(tempfon[lenPredpona]), oseba->telefon);
		
		for(int k = 0; k < lenPredpona; k++)
		{
			tempfon[k] = (predpona)[k];
		}
		printf("%s\n", tempfon);
	}
}

int main()
{
	char t1[] = "041398675";
	char t2[] = "030385091";
	
	Oseba** osebe = malloc(2 * sizeof(Oseba*));
	osebe[0] = malloc(sizeof(Oseba));
	osebe[0]->ime = "Alice";
	
	strcpy(osebe[0]->telefon, t1);
	
	osebe[1] = malloc(sizeof(Oseba));
	osebe[1]->ime = "Bob";
	
	strcpy(osebe[1]->telefon, t2);
	
	vstaviPredpono("+386", osebe, 2);

	free(osebe[0]);
	free(osebe[1]);
	free(osebe);

    return 0;
}

