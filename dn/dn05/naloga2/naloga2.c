/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include <stdio.h>

#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    // dopolnite ...
	int* c = *a;
	*a = *b;
	*b = c;
}

void uredi(int** a, int** b, int** c) {
    // dopolnite ...
	while(**a > **b || **a > **c || **b > **c)
	{
		if(**a > **b)
			zamenjaj(a, b);
		if(**b > **c)
			zamenjaj(b, c);
		if(**a > **c)
			zamenjaj(a, c);
	}
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
