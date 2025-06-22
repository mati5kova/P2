
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

long long memo[101][101][3][4];

long long rek(int preostaloBelih, int preostaloCrnih, int zaporednoBelih, int zaporednoCrnih) {
    if (preostaloBelih < 0 || preostaloCrnih < 0) return 0;
    
    if (preostaloBelih == 0 && preostaloCrnih == 0) return 1;
    
    long long res = memo[preostaloBelih][preostaloCrnih][zaporednoBelih][zaporednoCrnih];
    
    if (res != -1) return res;

    res = 0;
    
    // lahko dodamo belo, če nimamo že 2-eh belih
    if (preostaloBelih > 0 && zaporednoBelih < 2) {
        res += rek(preostaloBelih - 1, preostaloCrnih, zaporednoBelih + 1, 0);
    }
    
    // lahko dodamo črno, če nimamo že 3-eh črnih
    if (preostaloCrnih > 0 && zaporednoCrnih < 3) {
        res += rek(preostaloBelih, preostaloCrnih - 1, 0, zaporednoCrnih + 1);
    }
    
    memo[preostaloBelih][preostaloCrnih][zaporednoBelih][zaporednoCrnih] = res;
    
    return res;
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // napolnimo z -1
    for (int preostaloBelih = 0; preostaloBelih <= m; ++preostaloBelih)
    {
        for (int preostaloCrnih = 0; preostaloCrnih <= n; ++preostaloCrnih)
        {
             for (int zaporednoBelih = 0; zaporednoBelih < 3; ++zaporednoBelih)
             {
                 for (int zaporednoCrnih = 0; zaporednoCrnih < 4; ++zaporednoCrnih)
                 {
                    memo[preostaloBelih][preostaloCrnih][zaporednoBelih][zaporednoCrnih] = -1;
                 }
             }
        }
    }

    long long st = rek(m, n, 0, 0);
    printf("%lld\n", st);

    return 0;
}
