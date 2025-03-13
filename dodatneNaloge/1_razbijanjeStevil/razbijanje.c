#include <stdio.h>
#include <stdbool.h>

int dobiStevilo()
{
    char c = getchar();
    if(c == ' ')
        c = getchar(); //skippamo presledek med obema steviloma

    if(c == '\n')
        return 0; //nikoli ni input, lahko uporabimo kot return
    else
        return (c - '0');
}

long reverse(long stevilo)
{
    long num = 0;
    while(stevilo)
    {
        num = num * 10 + (stevilo % 10);
        stevilo /= 10;
    }
    return num;
}

long izpisiInVrniStevilo(long stevilo, int koliksenDel)
{
    /* 
        ideja je to da najprej obrnemo stevilo ker ce delamo z normalnim stevilom
        od leve proti desni in pridejo dve zaporedne nicle ki so z n-jem razrezane na pol
        se vodilne nicle zbrisejo zato delamo ""od nazaj do naprej" in so 
        "vodilne nicle" na koncu

        prilagojen output -> izpisujemo eno pa po eno in "\n" na koncu
    */


    bool zeIzpisanaKaksnaNeNicelnaStevka = false;

    for(int i = 0; i < koliksenDel; i++)
    {
        long izpis = stevilo % 10;
        if(izpis == 0 && !zeIzpisanaKaksnaNeNicelnaStevka && koliksenDel > 1)
        {
            //
        } else
        {
            printf("%ld", izpis);
            zeIzpisanaKaksnaNeNicelnaStevka = true;      
        }
        stevilo /= 10;
    }
    putchar('\n');

    return (stevilo); //ne znam pointerjev (se), getto resitev?

}

int main()
{
    long m;
    int n = 0;
    scanf("%ld", &m);
    m = reverse(m);
    
    while((n = dobiStevilo()) != 0)
    {
        m = izpisiInVrniStevilo(m, n);
    }
    return 0;
}