#include <stdio.h>

int vsotaStevk(int stevilo)
{
    int vsota = 0;
    while(stevilo)
    {
        vsota += (stevilo % 10);
        stevilo /= 10;
    }

    return vsota;
}

int main()
{
    int p, q, k;
    scanf("%d %d %d", &p, &q, &k);
    int pq = p * q;
    int vsota = 0;

    for(int i = 0; i < k; i++)
    {
        vsota = vsotaStevk(pq);
        pq = vsota;
    }

    printf("%d\n", vsota);

    return 0;
}