#include <stdio.h>

#define ZGORNJA_MEJA 4000000

int main()
{
	int i, vsota = 0;
	int a = 1, b = 2, c = 0;
	
	do
	{
		c = a + b;
		a = b;
		b = c;
		if(a % 2 == 0)
			vsota += a;
	}while(a <= ZGORNJA_MEJA && b <= ZGORNJA_MEJA);
	
	
	printf("%d\n", vsota);
	
	return 0;
}