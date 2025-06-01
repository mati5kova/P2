#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int seKolikoTransakcij, int* stanjeParkomata)
{
	if(seKolikoTransakcij == 0)
	{
		return 1;
	}
	
	int steviloNacinov = 0;
	
	// stranka plača s kovancem za 1€, vračilo ni potrebno
	stanjeParkomata[1] += 1;
	steviloNacinov += rek(seKolikoTransakcij - 1, stanjeParkomata);
	
	stanjeParkomata[1] -= 1;
	
	// stranka plača s kovancem za 2€
	stanjeParkomata[2] += 1;
	stanjeParkomata[1] -= 1; // vračilo denarja
	
	if(stanjeParkomata[1] >= 0)
	{
		steviloNacinov += rek(seKolikoTransakcij - 1, stanjeParkomata);		
	}
	
	stanjeParkomata[2] -= 1;
	stanjeParkomata[1] += 1;
	
	return steviloNacinov;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int stanjeParkomata[3];
	stanjeParkomata[1] = k;
	
	int stevilo = rek(n, stanjeParkomata);
	printf("%d\n", stevilo);
	
	
    return 0;
}

