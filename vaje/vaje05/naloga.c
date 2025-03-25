
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    // popravite / dopolnite ...
	int suma = 0;
	while(zac <= kon)
	{
		suma += *zac;
		zac++;
	}
	return suma;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    // dopolnite ...
	if(*indeks == -1)
	{
		*indeks = *kazalec - t;
	} else 
	{
		*kazalec = t + *indeks;
	}
}

void frekvenceCrk(char* niz, int** frekvence) {
    // dopolnite ...
	//angleska abeceda v ascii -> A:65, Z:90, a:97, z:122
	//crk skupaj: 26
	int* pogostostCrk = calloc(26, sizeof(int));
	
	while(*niz != '\0')
	{
		int crka = *niz;
		
		if('A' <= crka && crka <= 'Z')
		{
			pogostostCrk[crka - 'A']++;
		} else if('a' <= crka && crka <= 'z')
		{
			pogostostCrk[crka - 'a']++;
		}
		
		niz++;
	}
	*frekvence = pogostostCrk;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
