#include <stdio.h>

#define ZGORNJA_MEJA 100

int main()
{
	int i;
	unsigned long long vsotaKvadratov = 0;
	unsigned long long kvadratVsot = 0;
	
	for(i = 1; i <= ZGORNJA_MEJA; i++)
	{
		vsotaKvadratov += i*i;
		kvadratVsot += i;
		
	}
	
	unsigned long long razlika = kvadratVsot*kvadratVsot - vsotaKvadratov;
	
	printf("%llu\n", razlika);
	
	return 0;
}