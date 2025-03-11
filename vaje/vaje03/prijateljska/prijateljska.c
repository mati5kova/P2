#include <stdio.h>

int vsotaPD(int stevilo)
{
	int vsota = 0;

	for(int i = 1; i <= stevilo/2; ++i)
	{
		if(stevilo % i == 0)
			vsota += i;
	}

	return vsota;

}

int main()
{
	int n;
	scanf("%d", &n);
	int vpdn = vsotaPD(n);

	for(int i = 1; i < 2*n; ++i)
	{
		int vpdi = vsotaPD(i);

		if(n == vpdi && i == vpdn)
		{
			printf("%d\n", i);
			return 0;
		}
	}

	printf("NIMA\n");


	return 0;
}
