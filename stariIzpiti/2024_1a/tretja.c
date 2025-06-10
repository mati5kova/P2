#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void hanoi(int n, int k, char a, char b, char c, int* poteza)
{
    if(n == 1)
    {
        (*poteza)++;
        //printf("%c -> %c\n", a, c);
        if(c == 'b' && *poteza > k)
            printf("%d\n", *poteza);
    } else
    {
        hanoi(n - 1, k, a, c, b, poteza);
        (*poteza)++;
        //printf("%c -> %c\n", a, c);
        hanoi(n - 1, k, b, a, c, poteza);
    }
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);
    
    int poteza = 0;
    
    hanoi(n, k, 'a', 'b', 'c', &poteza);
    

    return 0;
}

