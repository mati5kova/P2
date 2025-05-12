#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	int vsota = 0;
	char c;
	bool validStevilo = true;
	int tempStevilo = 0;
	
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n')
		{
			if(validStevilo)
			{
				vsota += tempStevilo;
				tempStevilo = 0;
			}
			
			validStevilo = true;
			
			if(c == '\n')
				break;
			else
				continue;
		}
		
		if(!validStevilo) continue;
		
		if('0' <= c && c <= '9')
		{
			tempStevilo = tempStevilo * 10 + c - '0';
		} else
		{
			validStevilo = false;
			continue;
		}
		
		
	}
	
	printf("%d\n", vsota);
	
	return 0;
}