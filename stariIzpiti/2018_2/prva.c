#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() 
{
	int n;
	scanf("%d", &n);
	getchar(); // za presledek
	
	char c;
	char prejsnji = '\0';
	bool zeBilPlus = false;
	int razdalja = 0;
	int stevilo = 0;
	int vsotaRazdalj = 0;
	
	for(int i = 0; i < n; i++)
	{
		c = getchar();
		
		if(c == '-')
		{
			if(zeBilPlus)
			{
				razdalja++;
			} else
			{
				continue;
			}
		} else if(c == '+')
		{
			if(zeBilPlus)
			{
				razdalja++;
				stevilo++;
				vsotaRazdalj += razdalja;
				
				//printf("vmesna zakljucena razdalja: %d\n", razdalja);
				
				razdalja = 0;
			} else
			{
				zeBilPlus = true;
			}
		}
	}
	
	//printf("%d %d\n", vsotaRazdalj, stevilo);
	printf("%d\n", (int) (vsotaRazdalj / stevilo));
	

    return 0;
}

