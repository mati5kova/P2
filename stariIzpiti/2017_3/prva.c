#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int beri(int* stevilo)
{
	int st = 0;
	char c;
	bool negativno = false;
	while((c = getchar()) != ' ' && c != '\n' && c != EOF)
	{
		if(c == '-')
		{
			negativno = true;
			c = getchar();
		}
		st = st * 10 + c - '0';
	}
	
	*stevilo = negativno ? -st : st;
	
	if(c == ' ')
		return 1;
	if(c == '\n')
		return -1;
}

int main()
{
	bool prvoStevilo = true;
	bool pozitivno = true;
	int stevilo = 0;
	int* pStevilo = &stevilo;
	int prejsnjeStevilo = 0;
	
	while(1)
	{
		int i = beri(pStevilo);
		if(prvoStevilo)
		{
			prvoStevilo = false;
			prejsnjeStevilo = *pStevilo;
		} else
		{
			if(pozitivno)
			{
				if(*pStevilo < 0)
				{
					// se vedno pozitivno
					pozitivno = false;
					printf("%d\n", prejsnjeStevilo);
				}
			} else
			{
				if(*pStevilo > 0)
				{
					// ni vec negativno
					pozitivno = true;
					printf("%d\n", prejsnjeStevilo);
				}
			}
			prejsnjeStevilo = *pStevilo;
			
			if(i == -1)
			{
				break;
			}
		}
	}
	printf("%d\n", *pStevilo); // print zadnjega (vedno je zadnji clen neke skupine)
	
	
	return 0;
}