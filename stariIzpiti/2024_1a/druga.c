#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

void obdelaj(Vozlisce* zacetek, int k)
{
    if(zacetek == NULL || zacetek->naslednje == NULL)
        return;
    
    Vozlisce* temp = zacetek;
    int dolzinaSeznama = 0;
    
    while(temp != NULL)
    {
        
        Vozlisce* tempStetje = zacetek;
        int vsotaDoTrenutnega = 0;
        if(dolzinaSeznama >= k)
        {
            for(int i = 0; i < dolzinaSeznama - k; i++)
            {
                // premaknemo tempStetje na offset -k od trenutnega temp pointerja 
                // (vozlisca ki ga bomo potencialno odstranili)
                tempStetje = tempStetje->naslednje;
            }
            
            Vozlisce* prev;
            for(int i = 0; i < k; i++)
            {
                vsotaDoTrenutnega += tempStetje->podatek;
                prev = tempStetje;
                tempStetje = tempStetje->naslednje;
            }
            
            if(vsotaDoTrenutnega == temp->podatek)
            {
                // odstranimo vozlisce
                //printf("odstranil vozlisce: %d\n", temp->podatek);
                prev->naslednje = temp->naslednje;
                free(temp);
                temp = prev;
                dolzinaSeznama--;
            }
        }
        
        temp = temp->naslednje;
        dolzinaSeznama++;
    }
}

void izpisi(Vozlisce* zacetek)
{
    Vozlisce* temp = zacetek;
    while(temp != NULL)
    {
        printf("%d -> ", temp->podatek);
        temp = temp->naslednje;
    }
    printf("\n");
}

void cleanup(Vozlisce* zacetek)
{
    if(zacetek == NULL)
        return;
    cleanup(zacetek->naslednje);
    free(zacetek);
}

int main()
{
    /* testni primer iz izpita*/
    int podatki[] = {5, 4, 9, 18, 18, 7, 20, 6, 0, 13, 19, 2, 21};
    Vozlisce* zacetek = malloc(sizeof(Vozlisce));
    Vozlisce* temp = zacetek;
    int st = sizeof(podatki) / sizeof(podatki[0]);
    for(int i = 0; i < st && temp != NULL; i++)
    {
        temp->podatek = podatki[i];
        temp->naslednje = i == st - 1 ? NULL : malloc(sizeof(Vozlisce));
        temp = temp->naslednje;
    }
    
    // prvotno stanje
    izpisi(zacetek);
    
    int k = 3;
    obdelaj(zacetek, k);
    
    // stanje po obdelavi
    izpisi(zacetek);
    
    cleanup(zacetek);

    return 0;
}

