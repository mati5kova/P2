#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* t = calloc(10, sizeof(int));
	
	char c;
	while((c = getchar()) != '\n' && c != EOF)
	{
		if(c == ' ')
			continue;
		
		t[c - '0']++;
	}
	
	int count = 0;
	
	for(int i = 0; i < 10; i++)
	{
		if(t[i] != 0)
			count++;
	}
	
	printf("%d\n", count);
	
	free(t);
	
	return 0;
}