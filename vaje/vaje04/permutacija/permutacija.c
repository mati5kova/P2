#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int n, i, nova;
	scanf("%d", &n);
	
	// calloc da je default vrednost 0
	bool *tabela = (bool*) calloc(n, sizeof(bool));
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &nova);
		if(nova < 0 || nova >= n || tabela[nova] == true)
		{
			free(tabela);
			printf("NE\n");
			return 0;
		}
		
		tabela[nova] = true;
	}
	
	for(i = 0; i < n; i++)
	{
		if(tabela[i] == false)
		{
			free(tabela);
			printf("NE\n");
			return 0;
		}
	}
	
	printf("DA\n");
	
	free(tabela);
	return 0;
}