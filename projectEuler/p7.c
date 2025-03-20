#include <stdio.h>
#include <stdbool.h>

#define KATERO_PRA_STEVILO 1000100

bool jePrastevilo(unsigned long long n)
{
	if(n < 2)
		return false;
	if(n == 2 || n == 3)
		return true;
	if(n % 2 == 0 || n % 3 == 0)
		return false;
	
	for(unsigned long long i = 5; i*i <= n; i += 6)
	{
		if(n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	
	return true;
}

int main()
{
	int counter = 1;
	unsigned long long stevilo = 1;
	
	while(counter < KATERO_PRA_STEVILO)
	{
		stevilo += 2;
		if(jePrastevilo(stevilo))
			counter++;
	}

	printf("%llu\n", stevilo);
	
	return 0;
}