
/*
 * Zagon posami"cnega primera:
 *
 * gcc naloga1.c
 * ./a.out $(cat test01.param)
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 * 02--04: vsa stikala so prve oblike
 * 05--07: vsa stikala so druge oblike
 * 01, 08--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    // dopolnite ...

    for(int i = 1; i < argc; i++)
    {
        char* stikalo = malloc(21 * sizeof(char));
        strcpy(stikalo, argv[i]);
        if(stikalo[0] != '-') continue;

        if(stikalo[0] == stikalo[1] && stikalo[0] == '-')
        {
            printf("%s True\n", &(stikalo[2]));
        } else if(stikalo[0] == '-')
        {
            printf("%s %s\n", &(stikalo[1]), argv[i + 1]);
        }


        free(stikalo);
    }

    return 0;
}
