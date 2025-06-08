#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Oseba {
	int indeks; 				// indeks osebe
	struct _Oseba* prviOtrok;   // kazalec na otroka z manjšim indeksom oz. NULL,
								// če oseba nima otrok
	struct _Oseba* drugiOtrok;  // kazalec na otroka z večjim indeksom oz. NULL,
} Oseba; 						// če oseba nima otrok

Oseba* ustvariOsebo(int indeks, Oseba* prvi, Oseba* drugi)
{
	Oseba* nova = malloc(sizeof(Oseba));
	nova->indeks = indeks;
	nova->prviOtrok = prvi;
	nova->drugiOtrok = drugi;
	return nova;
}

/* ITERATIVNA REŠITEV - veliko boljša in bolj enostavna*/
Oseba* zgradi(int n, int* starsi)
{
	Oseba** osebe = malloc(n * sizeof(Oseba*));
	for(int i = 0; i < n; i++)
		osebe[i] = ustvariOsebo(i, NULL, NULL);
	
	Oseba* koren = NULL;
	
	for(int i = 0; i < n; i++)
	{
		int starsOdI = starsi[i];
		
		if(starsOdI == -1)
		{
			koren = osebe[i];
		} else
		{
			if(osebe[starsOdI]->prviOtrok == NULL)
				osebe[starsOdI]->prviOtrok = osebe[i];
			else
				osebe[starsOdI]->drugiOtrok = osebe[i];
		}
	}
	
	free(osebe);
	return koren;
}

void rekurzIzpis(Oseba* koren, int* mem, int len)
{
	if (koren == NULL)
        return;

    mem[len++] = koren->indeks;

    if (koren->prviOtrok == NULL && koren->drugiOtrok == NULL) {
        for (int i = 0; i < len; i++) {
            printf("%d", mem[i]);
            if (i < len - 1)
                printf(" <- ");
        }
        printf("\n");
        return;
    }

	rekurzIzpis(koren->prviOtrok, mem, len);
	rekurzIzpis(koren->drugiOtrok, mem, len);
}

int main()
{
	int starsi[] = {4, 5, 8, 1, 1, -1, 4, 8, 5};
	int n = 9;
	
	int mem[100];
	Oseba* koren = zgradi(n, starsi);
	
	rekurzIzpis(koren, mem, 0);	

    return 0;
}

/* 
//
//REKURZIVNA REŠITEV, NI SLABA SAMO VELIKO KODE JE
//


int* otrociIteOsebe(int n, int* starsi, int indeks)
{
	int* g = malloc(2 * sizeof(int));
	g[0] = -2;
	g[1] = -2;
	int lokalni_indeks = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(starsi[i] == indeks)
			g[lokalni_indeks++] = i;
	}
	return g;
}

Oseba* rekurz(int n, int* starsi, int iscemoOtroke_i_te_Osebe)
{
	Oseba* nova = malloc(sizeof(Oseba));
	nova->indeks = iscemoOtroke_i_te_Osebe;
	
	if(iscemoOtroke_i_te_Osebe == -1)
	{
		for(int i = 0; i < n; i++)
		{
			if(starsi[i] == -1)
				nova->indeks = i;
		}		
	}
	
	
	int* otrociOdI = otrociIteOsebe(n, starsi, iscemoOtroke_i_te_Osebe == -1 ? nova->indeks : iscemoOtroke_i_te_Osebe);
	
	//printf("i:%d; o1: %d; o2: %d\n", iscemoOtroke_i_te_Osebe, otrociOdI[0], otrociOdI[1]);
	
	if(otrociOdI[0] == -2 && otrociOdI[1] == -2)
	{
		return ustvariOsebo(iscemoOtroke_i_te_Osebe, NULL, NULL);
	}
	
	nova->prviOtrok = rekurz(n, starsi, otrociOdI[0]);

	nova->drugiOtrok = rekurz(n, starsi, otrociOdI[1]);
	
	
	return nova;
}

Oseba* zgradi(int n, int* starsi)
{
	Oseba* koren = NULL;
	
	koren = rekurz(n, starsi, -1);
	return koren;
}
*/