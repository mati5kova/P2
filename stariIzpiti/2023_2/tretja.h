#ifndef TRETJA_H
#define TRETJA_H

#include <stdbool.h>

typedef struct _Vozlisce {
    int           vsebina;  // vrednost v vozlišču
    struct _Vozlisce* desno; // kazalec na desnega soseda (NULL v zadnjem stolpcu)
    struct _Vozlisce* dol;   // kazalec na spodnjega soseda (NULL v zadnji vrstici)
} Vozlisce;

/* 
 * Vrne število vozlišč v vrstici, če štejemo od 'start' v desno dokler ni NULL.
 */
int sirina(Vozlisce* start);

/* 
 * Vrne število vozlišč v stolpcu, če štejemo od 'start' navzdol dokler ni NULL.
 */
int visina(Vozlisce* start);

/*
 * Ustvari in vrne nov Vozlisce z vsebino 'vsebina' ter kazalcem na 'desno'.
 * Novo->dol se nastavi na NULL.
 */
Vozlisce* ustvari(int vsebina, Vozlisce* desno);

/*
 * Sestavi povezano seznam vozlišč, ki vsebujejo elemente diagonale 
 * mreže, ki se začne v 'start'. Prav tako izračuna vsoto teh elementov v *vsota.
 * Če je start == NULL, vrne NULL in *vsota = 0.
 */
Vozlisce* diagonala(Vozlisce* start, int* vsota);

#endif /* TRETJA_H */
