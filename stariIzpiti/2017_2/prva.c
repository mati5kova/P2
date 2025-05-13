#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ST_NICEL 10001

int main()
{
	int* t = malloc(ST_NICEL * sizeof(int));
	int* izracun = malloc(ST_NICEL * sizeof(int));
	
	int k, dolzina = 0;
	
	char c;
	while((c = getchar()) != ' ')
	{
		t[dolzina++] = c - '0';
	}
	scanf("%d", &k);
	
	int prejsnjiCarry = 0;
	for(int i = dolzina - 1; i >= 0; i--)
	{
		int carry = 0;
		int pomnozeno = t[i] * k;
		if(pomnozeno > 9)
		{
			carry = pomnozeno / 10;
			pomnozeno = pomnozeno % 10;
		}
		
		izracun[i] = pomnozeno + prejsnjiCarry;
		prejsnjiCarry = carry;
	}
	
	
	if(prejsnjiCarry != 0)
		printf("%d", prejsnjiCarry);
	for(int i = 0; i < dolzina; i++)
	{
		printf("%d", izracun[i]);
	}
	printf("\n");
	
	free(t);
	free(izracun);
	
	return 0;
}