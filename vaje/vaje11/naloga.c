#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    // popravite / dopolnite ...
    int vsota = 0;
	Vozlisce* ptr = zacetek;
	
	while(ptr != NULL)
	{
		vsota += ptr->podatek;
		ptr = ptr->naslednje;
	}
	
	return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    // popravite / dopolnite ...
	if(zacetek == NULL)
		return 0;
	else
		return zacetek->podatek + vsotaR(zacetek->naslednje);
}


Vozlisce* ustvariNovoVozlisce(int element)
{
	Vozlisce* v = malloc(sizeof(Vozlisce));
	v->podatek = element;
	v->naslednje = NULL;
	
	return v;
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
	if(zacetek == NULL || zacetek->podatek >= element)
	{
		Vozlisce* novZacetek = ustvariNovoVozlisce(element);
		novZacetek->naslednje = zacetek;
		
		return novZacetek;
	}
	
	Vozlisce* ptr = zacetek;
	
	while(1)
	{		
		if(ptr->naslednje == NULL)
		{
			// element damo na konec
			Vozlisce* novKonec = ustvariNovoVozlisce(element);;			
			ptr->naslednje = novKonec;
			
			return zacetek;
		}
		
		int currVrednost = ptr->podatek;
		int nextVrednost = ptr->naslednje->podatek;
		
		if(element >= currVrednost && element <= nextVrednost)
		{
			// element bo vstavljen nekam v "sredino"
			Vozlisce* prevNaslednje = ptr->naslednje;
			Vozlisce* novoNaslednje = ustvariNovoVozlisce(element);
			
			ptr->naslednje = novoNaslednje;
			novoNaslednje->naslednje = prevNaslednje;
			
			return zacetek;
		}
		
		ptr = ptr->naslednje;
	}
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
	if(zacetek == NULL || element <= zacetek->podatek)
	{
		Vozlisce* v = ustvariNovoVozlisce(element);
		v->naslednje = zacetek;
		
		return v;
	} else
	{
		zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
	}
	
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
