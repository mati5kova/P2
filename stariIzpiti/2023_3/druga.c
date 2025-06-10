#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int** zmehcaj(int** slika, int n, int m, int d)
{
    int** t = malloc((n - 2*d) * sizeof(int*));
    for(int i = 0; i < n - 2*d; i++)
        t[i] = malloc((m - 2*d) * sizeof(int));
    
    
    for(int i = 0; i < n - 2*d; i++)
    {
        for(int j = 0; j < m - 2*d; j++)
        {            
            int vsotaSivin = 0, st = 0;
            int stranica = 2*d + 1;
            
            for(int islika = i; islika < i + stranica; islika++)
            {
                for(int jslika = j; jslika < j + stranica; jslika++)
                {
                    if(islika < 0 || jslika < 0 || islika >= n || jslika >= m) continue;
                    vsotaSivin += slika[islika][jslika];
                    st++;
                }
            }
            
            t[i][j] = (int) vsotaSivin / st;
        }
    }
    
    return t;
}

void izpisi(int** slika, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%4d", slika[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Primer 1: n=3, m=3, d=1
    {
        int n = 3, m = 3, d = 1;
        int* slika[3];
        int vrst0[] = {1, 2, 3};
        int vrst1[] = {4, 5, 6};
        int vrst2[] = {7, 8, 9};
        slika[0] = vrst0;
        slika[1] = vrst1;
        slika[2] = vrst2;

        int** out = zmehcaj(slika, n, m, d);
        printf("Primer 1 (3×3, d=1) → izhodna dim. (%d×%d):\n", n-2*d, m-2*d);
        izpisi(out, n-2*d, m-2*d);
        printf("Pričakovano:\n   5\n\n");

        // cleanup
        free(out[0]);
        free(out[1]);
        free(out);
    }

    // Primer 2: n=4, m=5, d=1
    {
        int n = 4, m = 5, d = 1;
        int* slika[4];
        int v0[] = { 10,  20,  30,  40,  50};
        int v1[] = { 60,  70,  80,  90, 100};
        int v2[] = {110, 120, 130, 140, 150};
        int v3[] = {160, 170, 180, 190, 200};
        slika[0] = v0;
        slika[1] = v1;
        slika[2] = v2;
        slika[3] = v3;

        int** out = zmehcaj(slika, n, m, d);
        printf("Primer 2 (4×5, d=1) → izhodna dim. (%d×%d):\n", n-2*d, m-2*d);
        izpisi(out, n-2*d, m-2*d);
        printf("Pričakovano:\n"
               "  70  80  90\n"
               " 120 130 140\n");

        // cleanup
        for(int i = 0; i < n-2*d; i++)
            free(out[i]);
        free(out);
    }

    return 0;
}

