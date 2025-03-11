#include <stdio.h>
#include <stdbool.h>

#define LIMITA 100000000000000000LLU

unsigned long long int zrcalno(unsigned long long int stevilo)
{
    unsigned long long int returnNum = 0;
    
    while(stevilo > 0)
    {
        returnNum = returnNum * 10 + (stevilo % 10);
        stevilo /= 10;
    }

    return returnNum;

}

bool jePalindrom(unsigned long long int stevilo)
{
	return stevilo == zrcalno(stevilo);
}

int main()
{
	int k, a, b, i, j;
	int steviloDomnevnih = 0;
	scanf("%d", &k);
	scanf("%d", &a);
	scanf("%d", &b);
	
	
	for(i = a; i <= b; ++i)
	{
		unsigned long long int num = i;
		bool najdeno = false;
		
		for(j = 1; j <= k; ++j)
		{
			num += zrcalno(num);
			
			if(num > LIMITA)
			{
				if(jePalindrom(num))
				{
					najdeno = true;
					break;
				}
				break;
			}
			
			else if(jePalindrom(num))
			{
				najdeno = true;
				break;
			}
		}
		
		steviloDomnevnih += (najdeno ? 0 : 1);
	}
	    
	printf("%d\n", steviloDomnevnih);

    return 0;
}
