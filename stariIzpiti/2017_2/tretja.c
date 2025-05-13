#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DOLZINA 1001

void beriDoKoncaVrstice()
{
	char c;
	while((c = getchar()) != '\n'){}
}

int main()
{
	int n; 
	scanf("%d\n", &n);
	int count = 0;
	
	//								 40  41   91   93   123  125
	//printf("%d %d %d %d %d %d\n", '(', ')', '[', ']', '{' ,'}');
	
	for(int i = 0; i < n; i++)
	{
		char* t = calloc(MAX_DOLZINA, sizeof(char));
	
		char c;
		int dolzina = 0;
		bool valid = true;
		while((c = getchar()) != '\n' && c != EOF)
		{
			printf("%c ", c);
			if(c == ')' || c == '}' || c == ']')
			{
				if(t[dolzina - 1] == c - 1 || t[dolzina - 1] == c - 2)
				{
					dolzina -= 1;
				} else
				{
					beriDoKoncaVrstice();
					valid = false;
					break;
				}
			} else
			{
				t[dolzina++] = c;
			}
		}
		printf("\n");
		
		if(valid && dolzina == 0)
			count++;
		
		free(t);
	}
	
	printf("%d\n", count);
	
	return 0;
}