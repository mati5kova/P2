
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "inverz.h"


long inverz(long x, long sp, long zg) {
	
	long sredina = (sp + zg) / 2;
	long i = sredina;
	long izracunanaVrednostFZaI;
	
	/*
	TA NACIN JE PREPOCASEN, IMPLEMENTIRAJ BINARY SEARCH
	for(i = sredina; i <= zg; i++)
	{
		izracunanaVrednostFZaI = f(i);
		if(izracunanaVrednostFZaI == x)
		{
			return i;
		}
	}
	*/
	
	while((izracunanaVrednostFZaI = f(i)) != x)
	{
		//printf("x: %ld, i: %ld, izracunanaVrednostFZaI: %ld, sp: %ld, zg: %ld\n", x, i, izracunanaVrednostFZaI, sp, zg);
		if(izracunanaVrednostFZaI > x)
		{
			zg = i - 1;
		} else
		{
			sp = i + 1;
		}

		i = (sp + zg) / 2;
	}
	
    return i;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
