#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char najdiNajvecjoAsciiVrednost(char* niz)
{
    char currMax = '\0';
    for(int i = 0; i < strlen(niz); i++)
        if(niz[i] > currMax)
            currMax = niz[i];
        
    return currMax;
}

void izpisiPresledke(int st)
{
    for(int i = 0; i < st; i++)
        printf(" ");

}

void rek(char* niz, int* stIzpisanihZnakov)
{
    int dolzina = strlen(niz);
    
    if(dolzina == 0) return;
    if(dolzina == 1)
    {
         izpisiPresledke(*stIzpisanihZnakov);
         printf("%c\n", niz[0]);
         (*stIzpisanihZnakov)++;
         
         return;
    }
    
    // izpisemo offset + originalni niz ki je prisel v rekurzijo
    // npr. programiram, ogrmiram, amiram, ...
    izpisiPresledke(*stIzpisanihZnakov);
    printf("%s\n", niz);
    
    // poiscemo katera crka v nizu ima najvecjo ascii vrednost
    char max = najdiNajvecjoAsciiVrednost(niz);
    int nadaljevanje = 0; // tocka od katere naprej bomo nadaljevali (npr. r, r, r, ...)
    
    for(int i = 0; i < dolzina; i++)
    {
        if(niz[i] == max)
        {
            // v buffer shranimo vse znake niza od zacetka do crke z najvecjo ascii vrednostjo
            
            nadaljevanje = i; // shranimo indeks nadaljevanja
            char* buffer = malloc(dolzina * sizeof(char));
            buffer[i] = '\0';
            
            for(int k = 0; k < i; k++)
                buffer[k] = niz[k];
            
            rek(buffer, stIzpisanihZnakov); // kličemo rek z novim nizom (npr. p, og, ami, ...)
            
            free(buffer);
            break;
        }
    }
    
    // izpisemo crko z najvecjo ascii vrednostjo (npr. r, r, r, ...) (lol vedno vse r)
    izpisiPresledke(*stIzpisanihZnakov);
    printf("%c\n", niz[nadaljevanje]);
    (*stIzpisanihZnakov)++; //tudi tukaj povečamo offset
    
    // v buffer shranimo podniz od crke z najvecjo ascii vrednostjo do konca vhodnega niza
    char* buffer = malloc(dolzina * sizeof(char));
    buffer[dolzina - nadaljevanje - 1] = '\0';
    for(int i = 0; i < dolzina - nadaljevanje; i++)
        buffer[i] = niz[nadaljevanje + i + 1];
    
    // ponovno klicemo rekurzijo (z bufferjem npr. ogramiram, amiram, ...)
    rek(buffer, stIzpisanihZnakov);

    free(buffer);
}

int main()
{
    char* niz = malloc(201 * sizeof(char));
    scanf("%s", niz);
    
    int stIzpisanihZnakov = 0;
    
    rek(niz, &stIzpisanihZnakov);
    
    free(niz);
    return 0;
}

