#include <stdio.h>

int main()
{
	int n, i = 1, stevilo = 1;
	scanf("%d", &n);
	
	do
	{
		if(stevilo % i == 0)
		{
			i++;
		} else 
		{
			stevilo++;
			i = 1;
		}
	} while(i != n + 1);
	
	printf("%d\n", stevilo);
	
	return 0;
}