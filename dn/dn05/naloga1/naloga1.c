/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    // popravite / dopolnite ...
	bool gledamoVDesno = true;
	while(1)
	{
		if(*t == 0)
		{
			if(gledamoVDesno)
			{
				*konec = t - 1;
				t -= *dolzina;
				gledamoVDesno = false;
			} else
			{
				(*dolzina)--;//-- ker stejemo desno niclo v dolzino
				return ++t;//++ ker trenutno smo na nicli
			}
		}
		
		t += gledamoVDesno ? 1 : -1;
		(*dolzina)++;
	}
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
