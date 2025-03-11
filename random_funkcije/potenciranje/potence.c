#include <stdio.h>

int potenciraj(int osnova, int potenca) {
    int i;
    int num = 1;
    
    for( i = 0; i < potenca; ++i) {
        num *= osnova;
    }

    return num;
}

int main() {

    printf("%d\n", potenciraj(2, 0));

    return 0;
}