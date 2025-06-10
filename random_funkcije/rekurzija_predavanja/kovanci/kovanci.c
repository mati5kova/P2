#include <stdio.h>
#include <stdlib.h>

int rek(int* kovanci, int indeks, int znesek)
{
    if(indeks == 0) return 1;
    
    int st = 0;
    for(int i = 0; i*kovanci[indeks] <= znesek; i++)
    {
        st += rek(kovanci, indeks - 1, znesek - i*kovanci[indeks]);
    }
    
    return st;
}

int main()
{
    int kovanci[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int stKovancev = 8;
    
    int st = rek(kovanci, stKovancev - 1, 555);
    printf("%d\n", st);
    
    return 0;
}