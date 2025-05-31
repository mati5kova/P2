#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int* t = malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &(t[i]));
	}

	int counter = 0;

	for(int i = 0; i < n; i++)
	{
		bool vidiDoKonca = true;
		
		for(int k = i + 1; k < n; k++)
		{
			if(t[k] > t[i])
			{
				vidiDoKonca = false;
				break;
			}
		}
		
		counter += vidiDoKonca ? 1 : 0;
	}
	
	printf("%d\n", counter);
	
	return 0;
}