#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int a, int b, int deljenec, int* tn)
{
	int stevilo = 0;
	
	if(tn[deljenec] == 0)
	{
		//printf("deljenec: %d\n", deljenec);
		tn[deljenec] = 1;
		stevilo += 1;
	}
	
	
	int f1 = (int) deljenec / a;
	int f2 = (int) deljenec / b;
	
	if(tn[f1] == 0)
	{
		stevilo += rek(a, b, f1, tn);
	}
	if(tn[f2] == 0)
	{
		stevilo += rek(a, b, f2, tn);
	}
	
	return stevilo;
}

int main()
{
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	
	int* tn = calloc(1000000, sizeof(int));
	
	int stevilo = rek(a, b, n, tn);
	printf("%d\n", stevilo);
	
	free(tn);
	
    return 0;
}

