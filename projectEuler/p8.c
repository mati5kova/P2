#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VELIKOST 1000
#define STEVILO_SOSEDNJIH 13

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	
	long maxProduct = 0;
	
	int *t = malloc(VELIKOST * sizeof(int));
	for(int i = 0; i < VELIKOST; i++)
	{
		//og input ma '\n' notr
		char c = getchar();
		if(c == '\n')
			c = getchar();
		t[i] = c - '0';
	}
	
	for(int i = 0; i <= (VELIKOST - STEVILO_SOSEDNJIH + 1); i++)
	{
		long currProduct = 1;
		for(int k = i; k < i + (STEVILO_SOSEDNJIH); k++)
		{
			
			if(currProduct * t[k] < currProduct) // * 0
			{
				i = k + 1;
				break;
			}
			currProduct *= t[k];
			
		}
		if(currProduct > maxProduct)
		{
			maxProduct = currProduct;
		}
		
	}
	
	printf("%ld\n", maxProduct);
	
	free(t);
	return 0;
}