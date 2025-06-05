#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool preveriVsoto(int* t, int target, int stEl)
{
	int suma = 0;
	for(int i = 0; i < stEl; i++)
	{
		suma += t[i];
	}
	
	return suma == target ? true : false;
}

void izpisiRazbitNiz(char* niz, int* t, int stRazbitij)
{
	int offset = 0;
	for(int i = 0; i < stRazbitij; i++)
	{
		int subset = t[i];
		
		for(int k = offset; k < offset + subset; k++)
		{
			putchar(niz[k]);
		}
		if(i != stRazbitij - 1)
			putchar('|');
		
		offset += subset;
	}
	putchar('\n');
}

void rek(char* niz, int n, int a, int b, int stRazbitij, int* t)
{
	if(stRazbitij > b)
		return;
	if(stRazbitij >= a && stRazbitij <= b)
	{
		// preveri razbitje IN NADALJUJ Z ISKANJEM V TEJ VEJI
		if(preveriVsoto(t, n, stRazbitij))
		{
			izpisiRazbitNiz(niz, t, stRazbitij);		
		}
	}
	
	for(int i = 1; i < n; i++)
	{
		t[stRazbitij] = i;
		rek(niz, n, a, b, stRazbitij + 1, t);
	}
}

int main()
{
	char niz[16];
	int a, b;
	
	scanf("%s %d %d", niz, &a, &b);
	
	int n = strlen(niz);
	
	int t[n+1];
	rek(niz, n, a, b, 0, t);
	
    return 0;
}

