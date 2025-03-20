#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define STEVILO 600851475143L

bool jePrastevilo(long a)
{
	for(int i = 2; i <= sqrt(a); i ++)
	{
		if(a % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int i, najvecjePraStevilo = 0;

	
	for(i = 1; i < sqrt(STEVILO); i += 2)
	{
		if(STEVILO % i == 0 && jePrastevilo(i))
			najvecjePraStevilo = i;
	}
	
	printf("%d\n", najvecjePraStevilo);
	
	return 0;
}