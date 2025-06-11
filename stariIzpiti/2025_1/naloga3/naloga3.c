
/*
 * Zagon posami"cnega primera:
 *
 * gcc -Dtest test01.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Javni testni primeri:
 *
 * 02--05: 
 *    V teh primerih se ne preverja istovetnost vozli"s"c vhodnega seznama in
 *    izhodne konstrukcije.
 *
 * 01, 06--10: 
 *    V teh primerih se preverja tudi istovetnost vozli"s"c vhodnega seznama
 *    in izhodne konstrukcije.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

Zunanje* ustvari(Notranje* prvo, Notranje* zadnje, Zunanje* dol)
{
    Zunanje* n = malloc(sizeof(Zunanje));
    n->prvo = prvo;
    n->zadnje = zadnje;
    n->dol = dol;
    return n;
}

Zunanje* porazdeli(Notranje* zacetek, int k) {
    // popravite / dopolnite ...
    Zunanje* absLevoZgoraj = ustvari(NULL, NULL, NULL);
    Zunanje* t_levoZgoraj = absLevoZgoraj;

    Notranje* t_temp = zacetek;

    while(t_temp != NULL)
    {
        for(int i = 0; i < k; i++)
        {
            if(t_temp == NULL) break;

            Notranje* kopija = malloc(sizeof(Notranje));
            memcpy(kopija, t_temp, sizeof(Notranje));

            if(t_levoZgoraj->prvo == NULL)
            {
                t_levoZgoraj->prvo = t_temp;
                t_levoZgoraj->zadnje = t_temp;

                t_levoZgoraj->prvo->desno = NULL;
            } else
            {
                Notranje* tempZnotrajVrstice = t_levoZgoraj->prvo;
                while(tempZnotrajVrstice->desno != NULL)
                {
                    tempZnotrajVrstice = tempZnotrajVrstice->desno;
                }
                tempZnotrajVrstice->desno = t_temp;
                t_levoZgoraj->zadnje = t_temp;
                t_levoZgoraj->zadnje->desno = NULL;
            }

            if(t_levoZgoraj->dol == NULL && i != k -1 )
            {
                t_levoZgoraj->dol = ustvari(NULL, NULL, NULL);
            }
            t_levoZgoraj = t_levoZgoraj->dol;
            t_temp = kopija->desno;
            
            free(kopija);
        }
        t_levoZgoraj = absLevoZgoraj;
    }

    return absLevoZgoraj;
}

#ifndef test

int main() {
    return 0;
}

#endif
