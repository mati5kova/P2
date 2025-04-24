#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool jeUrejeno(int* t, int len)
{
	for(int i = 1; i < len; i++)
	{
		// narascajoce urejeno
		if(t[i] < t[i - 1])
			return false;
	}
	return true;
}

void zamenjaj(int* t, int i, int j, int r)
{
	for(int e = 0; e < r; e++)
	{
		int temp = t[j + e];
		t[j + e] = t[i + e];
		t[i + e] = temp;
	}
}

int menjaj(int* t, int n, int k, int r)
{
	int count = 0;
	
	if(k >= 0 && jeUrejeno(t, n))
	{
		// ce imamo se dovolj iskanj na voljo (ali pa smo koncali) in je urejeno povecamo counter za 1
		// ne prenehamo z iskanjem zaradi npr. testnega primera 2
		//	 -> dobimo v funkcijo ze urejeno tabelo ampak moramo iskati naprej
		count += 1;
	}
	if(k == 0)
	{
		// ko zmanjka poskusov iskanja vrnemo stevec
		return count;
	}
	
	for(int i = 0; i <= n - 2*r; i++)
	{
		for(int j = i + r; j <= n - r; j++)
		{
			zamenjaj(t, i, j, r);
			count += menjaj(t, n, k - 1, r);
			zamenjaj(t, i, j, r);
		}
	}
	return count;
}

int main()
{
	int n, k, r;
	scanf("%d %d %d", &n, &k, &r);
	
	int* t = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	
	int steviloNacinov = menjaj(t, n, k, r);
	printf("%d\n", steviloNacinov);
	
	free(t);
	return 0;
}