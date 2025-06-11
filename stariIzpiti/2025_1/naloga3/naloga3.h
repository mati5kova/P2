
#ifndef _SEZNAMI3_H
#define _SEZNAMI3_H

typedef struct Zunanje Zunanje;
typedef struct Notranje Notranje;

struct Zunanje {
    Notranje* prvo;
    Notranje* zadnje;
    Zunanje* dol;
};

struct Notranje {
    int podatek;
    Notranje* desno;
};

Zunanje* porazdeli(Notranje* zacetek, int k);

#endif
