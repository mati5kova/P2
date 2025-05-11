#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

bool obiskaniVsiKamni(int* t, int dolzina)
{
	for(int i = 0; i < dolzina; i++)
		if(t[i] == 0 && i !=  0)
			return false;
	
	return true;
}

int skaci(int* t, int pozicija, int n, int a, int b, int* map, int stSkokov)
{
	if(pozicija >= n || pozicija < 0)
		return 0;
	
	if(obiskaniVsiKamni(t, n))
	{
		// za izpis poti
		for(int i = 0; i < n; i++)
			printf("%d ", map[i]);
		printf("\n");
		return 1;
	}
		
	int stevilo = 0;
	for(int skok = a; skok <= b; skok++)
	{
		int* tempMap = calloc(n, sizeof(int)); // za vmesno izpisovanje
		int* temp = calloc(n, sizeof(int));
		for(int i = 0; i < n; i++)
		{
			tempMap[i] = map[i];
			temp[i] = t[i];
		}
		
		// pozitiven skok
		if(pozicija + skok < n && temp[pozicija + skok] == 0)
		{
			tempMap[stSkokov + 1] = pozicija + skok; // zapisemo kam je bil naslednji skok
			temp[pozicija + skok] = 1; // oznacimo da smo na to mesto ze skocili (ne moremo dvakrat na isto)
			stevilo += skaci(temp, pozicija + skok, n, a, b, tempMap, stSkokov + 1);
		}
		
		// resetiramo
		for(int i = 0; i < n; i++)
		{
			tempMap[i] = map[i];
			temp[i] = t[i];
		}
		
		
		// negativen skok
		if(pozicija - skok > 0 && temp[pozicija - skok] == 0)
		{
			tempMap[stSkokov + 1] = pozicija - skok;
			temp[pozicija - skok] = 1;
			stevilo += skaci(temp, pozicija - skok, n, a, b, tempMap, stSkokov + 1);			
		}
		
		free(temp);
		free(tempMap);
	}
	
	return stevilo;
}

int main()
{
	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	
	int* t = calloc(n, sizeof(int));
	int* map = calloc(n, sizeof(int));
	
	printf("%d\n", skaci(t, 0, n, a, b, map, 0));
	
	free(t);
	free(map);
	
	return 0;
}