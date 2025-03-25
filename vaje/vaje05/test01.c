
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int main() {
    int* t = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        t[i] = i + 1;  // Tabela: 1, 2, ..., 10
    }

    int* zac = &t[2];  // kaže na 3
    int* kon = &t[5];  // kaže na 6

    int rezultat = vsota(zac, kon);
    printf("%d\n", rezultat);  // Izpis: 3 + 4 + 5 + 6 = 18
	
	int t1[] = {1, 2, 3, 4, 5};
    printf("%d\n", vsota(&t1[0], &t1[4])); // Expected: 15

    // Test 2
    int t2[] = {10, 20, 30, 40};
    printf("%d\n", vsota(&t2[2], &t2[2])); // Expected: 30

    // Test 3
    int t3[] = {5, 10, 15, 20, 25, 30};
    printf("%d\n", vsota(&t3[1], &t3[4])); // Expected: 70

    free(t);
    return 0;
}

