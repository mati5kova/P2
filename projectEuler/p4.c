#include <stdio.h>
#include <stdbool.h>

int reverseNumber(int num)
{
	int retNum = 0;
	
	while(num)
	{
		retNum = retNum * 10 + (num % 10);
		num /= 10;
	}
	
	return retNum;
}

bool jePalindrom(int num)
{
	return num == reverseNumber(num);
}

int main()
{
	int najvecje = 0;
	
	for(int i = 100; i < 1000; i++)
	{
		for(int k = 100; k < 1000; k++)
		{
			int stevilo = i * k;
			if(jePalindrom(stevilo) && stevilo > najvecje)
			{
				najvecje = stevilo;
				i = k;
			}
		}
	}
	
	printf("%d\n", najvecje);
	
	return 0;
}