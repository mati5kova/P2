
/*
 * Zagon posami"cnega primera:
 *
 * gcc naloga4.c
 * ./a.out < test01.in
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga4
 * make test
 *
 * Javni testni primeri:
 * 01--04: m + n <= 20
 * 05--07: m + n <= 30
 * 08--10: m + n <= 100
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool preveri(int* t, int dolzina)
{
    int prev = -1;
    int stPrev = 0;
    for(int i = 0; i < dolzina; i++)
    {
        int el = t[i];
        if(prev == -1)
        {
            prev = el;
            stPrev = 1;
            continue;
        }

        if(prev == el)
        {
            stPrev++;
        } else
        {
            if(prev == 0) // bela -> max 2
            {
                if(stPrev > 2)
                    return false;
                
            } else
            {
                if(stPrev > 3)
                    return false;
            }
            prev = el;
            stPrev = 1;
        }
    }
    if(prev == 0) // bela -> max 2
    {
        if(stPrev > 2)
            return false;
        
    } else
    {
        if(stPrev > 3)
            return false;
    }

    return true;
}

void izpisi(int* t, int dolzina)
{
    for(int i = 0; i  < dolzina; i++)
        printf("%d",t[i]);
    printf("\n");
}

int rek(int max, int m, int n, int* t, int dolzina)
{
    if(m == 0 && n > 3) return 0;
    if(n == 0 && m > 2) return 0;

    if(dolzina == max)
    {
        // preveri rešitev in po potrebi return 1
        if(preveri(t, dolzina))
        {
            return 1;
        }
        return 0;
    }

    int st = 0;

    // dodamo belo
    if(m > 0)
    {
        t[dolzina] = 0; // 0 <- bela
        st += rek(max, m - 1, n, t, dolzina + 1);

    }
    

    // dodamo črno
    if(n > 0)
    {
        t[dolzina] = 1;
        st += rek(max, m, n- 1, t, dolzina + 1);     
    }
    

    return st;
}

int main() {
    // dopolnite ...
    int m, n;
    scanf("%d %d", &m, &n);


    int* t = malloc((m+n)*sizeof(int));

    int st = rek(m+n,m, n, t, 0);
    printf("%d\n", st);

    free(t);
    return 0;
}
