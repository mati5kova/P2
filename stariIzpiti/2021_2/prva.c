#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	char* t = malloc(14000 * sizeof(char));
	char c;
	int stEl = 0;
	while((c = getchar()) != EOF && c != '\n' && c != ' ')
	{
		t[stEl++] = c;
	}
	
	int ostanekNaZacetku = stEl % 3;
	int globalniIndeks = 0;
	
	for(int i = 0; i < ostanekNaZacetku; i++)
	{
		printf("%c", t[globalniIndeks++]);
	}
	
	for(int i = 0; i < (stEl - ostanekNaZacetku)/3; i++)
	{
		if(stEl > 3) // za input npr. 123
		{
			printf(".");			
		}
		for(int k = 0; k < 3; k++)
		{
			printf("%c", t[globalniIndeks++]);
		}
	}
	printf("\n");
	
	free(t);
    return 0;
}

