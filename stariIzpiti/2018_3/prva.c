#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() 
{
	int n;
	scanf("%d", &n);
	getchar(); // za presledek
	
	bool znotrajBesede = false;
	
	for(int i = 0; i < n; i++)
	{
		char znak = getchar();
		
		if(znak == '_')
		{
			znotrajBesede = false;
			putchar(znak);
		}
		
		if(!znotrajBesede)
		{
			if(znak != '_')
			{
				putchar(toupper(znak));
				znotrajBesede = true;
			}
		} else
		{
			putchar(znak);
		}
	}
	
	putchar('\n');
	
    return 0;
}

