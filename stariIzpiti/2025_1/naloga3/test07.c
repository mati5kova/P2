
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

Notranje* zgradi(int* t, int n, Notranje** element2naslov) {
    Notranje* prvo = NULL;
    Notranje* zadnje = NULL;
    for (int i = 0; i < n; i++) {
        Notranje* v = calloc(1, sizeof(Notranje));
        v->podatek = t[i];
        element2naslov[v->podatek] = v;
        if (prvo == NULL) {
            prvo = zadnje = v;
        } else {
            zadnje->desno = v;
            zadnje = zadnje->desno;
        }
    }
    return prvo;
}

void izpisiNotranje(Notranje* zacetek) {
    printf("[");
    Notranje* v = zacetek;
    while (v != NULL) {
        if (v != zacetek) {
            printf(", ");
        }
        printf("%d", v->podatek);
        v = v->desno;
    }
    printf("]");
}

void izpisiZunanje(Zunanje* glava) {
    printf("[");
    Zunanje* v = glava;
    while (v != NULL) {
        if (v != glava) {
            printf(", ");
        }
        izpisiNotranje(v->prvo);
        v = v->dol;
    }
    printf("]");
}

void pocistiNotranje(Notranje* prvo) {
    Notranje* v = prvo;
    while (v != NULL) {
        Notranje* brisi = v;
        v = v->desno;
        free(brisi);
    }
}

void pocistiZunanje(Zunanje* glava) {
    Zunanje* v = glava;
    while (v != NULL) {
        pocistiNotranje(v->prvo);
        Zunanje* brisi = v;
        v = v->dol;
        free(brisi);
    }
}

int maksimum(int* t, int n) {
    int naj = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] > naj) {
            naj = t[i];
        }
    }
    return naj;
}

void preveriIstovetnost(Zunanje* glava, Notranje** element2naslov) {
    Zunanje* z = glava;
    while (z != NULL) {
        Notranje* n = z->prvo;
        while (n != NULL) {
            printf("%d", element2naslov[n->podatek] == n);
            n = n->desno;
        }
        z = z->dol;
    }
}

int TABELA[] = {4143, 7080, 7151, 2229, 1131, 860, 8693, 7770, 1497, 6071, 3914, 6730, 9235, 340, 3735, 3257, 4732, 6917, 9258, 3937, 8645, 2123, 2172, 8709, 1818, 1015, 1470, 6832, 3548, 6022, 6151, 632, 4662, 9142, 8942, 947, 6222, 2348, 798, 1065, 880, 1073, 7682, 3015, 6175, 8302, 4725, 8753, 3357, 9008, 2724, 3575, 1731, 9327, 3648, 5641, 1668, 7837, 9530, 2945, 4236, 7083, 5703, 4119, 4659, 2030, 1313, 1127, 6365, 7763, 57, 3491, 7979, 1915, 5527, 2948, 2352, 9001, 5021, 3173, 2879, 7787, 3332, 4039, 6750, 854, 8200, 375, 1213, 1794, 7936, 2800, 2179, 1293, 718, 8555, 4521, 4180, 4960, 4212, 8832, 536, 8196, 7513, 3075, 9715, 1558, 7673, 853, 6339, 2391, 5920, 7675, 5901, 956, 4024, 3801, 4298, 500, 479, 3306, 2062, 8758, 293, 8034, 6986, 1345, 5052, 4590, 8801, 1918, 7971, 5374, 3141, 412, 5861, 5734, 9101, 3172, 8056, 887, 3560, 2217, 2012, 1484, 2754, 208, 8147, 2856, 4483, 9795, 828, 584, 2728, 7271, 1751, 2250, 50, 5729, 606, 5646, 820, 9521, 4667, 2871, 2961, 9558, 8238, 5491, 5360, 748, 8617, 9202, 4226, 5477, 6848, 4677, 1265, 9854, 5599, 3060, 9664, 2665, 1656, 2055, 6168, 8107, 2658, 8087, 9301, 7545, 5334, 1720, 6256, 1048, 7980, 4649, 5685, 9071, 1824, 2527, 667, 7449, 2148, 3425, 8604, 6078, 2496, 7897, 8669, 1769, 6341, 6254, 8744, 1019, 6263, 1571, 2304, 1134, 8964, 8703, 3198, 7360, 342, 3190, 1021, 262, 384, 7915, 7676, 7829, 7664, 3943, 8261, 5262, 2776, 5902, 8076, 5835, 9326, 2938, 8018, 9846, 4519, 7172, 5842, 7005, 2625, 4476, 2395, 9484, 8792, 5471, 7681, 7575, 7546, 3446, 1866, 6241, 9499, 9299, 5725, 3072, 6578, 1388, 9180, 7869, 8977, 6622, 1897, 1726, 8526, 5071, 8814, 3752, 1441, 8117, 9358, 5007, 9215, 9019, 7922, 804, 8112, 9980, 2753, 6472, 9060, 5715, 9663, 156, 9375, 6741, 3554, 3788, 345, 2116, 3759, 7352, 8593, 4152, 4381};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 67);

    printf("Izhod: ");
    izpisiZunanje(glava);
    printf("\n");

    printf("Istovetnost vozlisc: ");
    preveriIstovetnost(glava, element2naslov);
    printf("\n");

    pocistiZunanje(glava);
    free(element2naslov);
    return 0;
}
