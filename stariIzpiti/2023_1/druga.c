#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int vsota(int* t, int stevilo)
{
	int suma = 0;
	for(int i = 0; i < stevilo; i++)
		suma += t[i];
	return suma;
}

void izpisiCeNarascajoce(int* t, int st)
{
	for(int i = 1; i < st; i++)
	{
		if(t[i] < t[i-1])
			return;
	}
	
	for(int i = 0; i < st; i++)
	{
		printf("%d", t[i]);
		if(i != st - 1)
			printf("+");
	}
	printf("\n");
}

void rek(int n, int a, int b, int* t, int stElementov)
{
	if(stElementov > b)
		return;
	if(stElementov >= a && stElementov <= b)
	{
		int suma = vsota(t, stElementov);
		if(suma == n)
			izpisiCeNarascajoce(t, stElementov);
		//nadaljuj z iskanjem
	}
		
	for(int i = 1; i < n; i++)
	{
		t[stElementov] = i;
		rek(n, a, b, t, stElementov + 1);
	}
}

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	
	int* t = calloc(n, sizeof(int));
	
	rek(n, a, b, t, 0);
	
	free(t);
    return 0;
}

