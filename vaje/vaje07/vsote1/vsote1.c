#include <stdio.h>

int vsota(int trenutnaVsota, int cilj, int zgornjaMeja)
{
	if(trenutnaVsota == cilj)
	{
		return 1;
	} else if(trenutnaVsota > cilj)
	{
		return 0;
	}
	
	int stevilo = 0;
	for(int i = zgornjaMeja; i >= 1; i--)
	{
		stevilo += vsota(trenutnaVsota + i, cilj, i);
	}
	return stevilo;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	
	int stNacinov = vsota(0, n, k);
	printf("%d\n", stNacinov);
	
	return 0;
}