// test3_1x5.c
#include <stdio.h>
#include <stdlib.h>
#include "tretja.h"

int main() {
    int h = 1, w = 5;
    int i;

    int vrednosti[1][5] = { { 10, 20, 30, 40, 50 } };

    Vozlisce* mreza[1][5];
    for (i = 0; i < w; i++) {
        mreza[0][i] = ustvari(vrednosti[0][i], NULL);
    }
    for (i = 0; i < w - 1; i++) {
        mreza[0][i]->desno = mreza[0][i + 1];
    }

    Vozlisce* start = mreza[0][0];
    int vsota = 0;

    Vozlisce* diag = diagonala(start, &vsota);

    printf("Diagonala: ");
    for (Vozlisce* cur = diag; cur != NULL; cur = cur->desno) {
        printf("%d ", cur->vsebina);
    }
    printf("\nVsota vsebin diagonale = %d\n", vsota);

    while (diag != NULL) {
        Vozlisce* tmp = diag->desno;
        free(diag);
        diag = tmp;
    }

    for (i = 0; i < w; i++) {
        free(mreza[0][i]);
    }

    return 0;
}

