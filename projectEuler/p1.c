#include <stdio.h>

#define ZGORNJA_MEJA 1000

int main()
{
	int i, vsota = 0;
	
	for(i = 0; i < ZGORNJA_MEJA; i++)
	{
		if(i % 3 == 0 || i % 5 == 0)
		{
			vsota += i;
		}
	}
	
	printf("%d\n", vsota);
	
	return 0;
}