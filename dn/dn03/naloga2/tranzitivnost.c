
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranzitivnost(int a, int b) {
    // popravite / dopolnite ...
	int x, y, z;
	bool fxy, fyz, fxz;
	
	bool tranzitivna = true;
	bool antitranzitivna = true;
	
	for(x = a; (x <= b) && (tranzitivna || antitranzitivna); x++)
	{
		for(y = a; (y <= b) && (tranzitivna || antitranzitivna); y++)
		{
			fxy = f(x, y);
			for(z = a; (z <= b) && (tranzitivna || antitranzitivna); z++)
			{	
				fyz = f(y, z);
				
				if(fxy && fyz)
				{
					fxz = f(x, z);
					if(fxz)
					{
						antitranzitivna = false;
					} else 
					{						
						tranzitivna = false;
					}
				}
			}
		}
	}
	
	//printf("tranz: %d, antitranz: %d\n", tranzitivna, antitranzitivna);
	
	if(tranzitivna && antitranzitivna)
	{
		return 1;
	} else if(tranzitivna && !antitranzitivna)
	{
		return 2;
	} else if(antitranzitivna && !tranzitivna)
	{
		return 3;
	} else
	{
		return 4;
	}
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
