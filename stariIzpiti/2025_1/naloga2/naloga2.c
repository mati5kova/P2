
/*
 * Zagon posami"cnega primera:
 *
 * gcc naloga2.c
 * ./a.out < test01.in
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Javni testni primeri:
 * 02--04: h = 1
 * 01, 05--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // dopolnite ...
    int h,w ,n;
    char* imeDatoteke = malloc(21*sizeof(char));
    scanf("%s %d %d %d", imeDatoteke, &h, &w, &n);
    int** t = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        t[i] = malloc(2 * sizeof(int));


    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &(t[i][0]), &(t[i][1]));
    }

    FILE* f = fopen(imeDatoteke, "rb");
    if(f == NULL)
    {
        printf("Napaka pri odpiranju datoteke\n");
        free(imeDatoteke);
        for(int i = 0; i < n; i++)
            free(t[i]);
        free(t);
        exit(1);
    }

    unsigned char** matrika = malloc(h * sizeof(unsigned char*));
    for(int i = 0; i < h; i++)
        matrika[i] = malloc(w * sizeof(char));

    int i_v = 0;
    int i_s = 0;

    while(1)
    {
        unsigned char bajt;
        short st = fread(&bajt, sizeof(unsigned char), 1, f);
        if(st == 0)
        {
            break;
        }

        for(int i = 7; i >= 0; i--)
        {
            unsigned char bit = bajt & (1 << i);

            if(i_s >= w)
            {
                i_s = 0;
                i_v++;
            }
            matrika[i_v][i_s] = bit > 0 ? '1' : '0';
            i_s++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%c\n", matrika[t[i][0]][t[i][1]]);
    }


    for(int i = 0; i < h; i++)
        free(matrika[i]);
    free(matrika);

    fclose(f);
    free(imeDatoteke);
    
    for(int i = 0; i < n; i++)
        free(t[i]);
    free(t);
    return 0;
}
