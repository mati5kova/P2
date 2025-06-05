#include <stdio.h>
#include <stdlib.h>
#include "tretja.h"

int main() {
    int h = 3, w = 4;
    int i, j;

    int vrednosti[3][4] = {
        {  1,  2,  3,  4 },
        {  5,  6,  7,  8 },
        {  9, 10, 11, 12 }
    };

    Vozlisce* mreza[3][4];
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            mreza[i][j] = (Vozlisce*)malloc(sizeof(Vozlisce));
            if (!mreza[i][j]) {
                fprintf(stderr, "Napaka pri malloc\n");
                return 1;
            }
            mreza[i][j]->vsebina = vrednosti[i][j];
            mreza[i][j]->desno = NULL;
            mreza[i][j]->dol   = NULL;
        }
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (j < w - 1) {
                mreza[i][j]->desno = mreza[i][j + 1];
            }
            if (i < h - 1) {
                mreza[i][j]->dol = mreza[i + 1][j];
            }
        }
    }

    Vozlisce* start = mreza[0][0];
    int vsota = 0;

    Vozlisce* diag = diagonala(start, &vsota);

    printf("Diagonala: ");
    for (Vozlisce* cur = diag; cur != NULL; cur = cur->desno) {
        printf("%d ", cur->vsebina);
    }
    printf("\n");
    printf("Vsota vsebin diagonale = %d\n", vsota);

    {
        Vozlisce* tmp;
        while (diag != NULL) {
            tmp = diag->desno;
            free(diag);
            diag = tmp;
        }
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            free(mreza[i][j]);
        }
    }

    return 0;
}
