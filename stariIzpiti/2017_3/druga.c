#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define VELIKOST 10001

int main()
{
	int* n = malloc(VELIKOST * sizeof(int));
	int* rez = malloc(VELIKOST * sizeof(int));
	
	char c;
	int dolzina = 0;
	while((c = getchar()) != ' ')
	{
		n[dolzina++] = c - '0';
	}
	
	int k;
	scanf("%d", &k);
	
	int carryOver = 0;
	int pozRez = 0;
	for(int i = 0; i < dolzina; i++)
	{
		if(carryOver == 0 && n[i] == 0)
		{
			rez[pozRez++] = 0;
		} else if(10*carryOver + n[i] < k)
		{
			carryOver = carryOver * 10 + n[i];
			if(i != 0)
				rez[pozRez++] = 0;
		} else
		{
			int rezultat = (int) (10 * carryOver + n[i]) / k;
			
			carryOver = (10 * carryOver + n[i]) - (rezultat*k);
			rez[pozRez++] = rezultat;
		}
	}
	
	for(int i = 0; i < pozRez; i++)
	{
		printf("%d", rez[i]);
	}
	printf("\n");
	
	
	free(n);
	free(rez);
	
	return 0;
}