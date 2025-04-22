#include <stdio.h>
#include <stdlib.h>

void nizi(int n, char c1, char c2, char* niz, int indeks) 
{
	if(indeks <= n)
	{
		niz[indeks] = '\0';
		printf("%s\n", niz);
	} else return;
	
	for(char c = c1; c <= c2; c++)
	{
		niz[indeks] = c;
		nizi(n, c1, c2, niz, indeks + 1);
	}
}


int main()
{
	int n;
	char c1, c2;
	scanf("%d %c %c", &n, &c1, &c2);
		
	for(char i = c1; i <= c2; i++)
	{
		char niz[21];
		niz[0] = i;
		nizi(n, c1, c2, niz, 1);
	}

	return 0;
}