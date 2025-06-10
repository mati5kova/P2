#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int _abs(int a, int b)
{
    return a - b < 0 ? 0 - a + b : a - b;
}

int STEVILO_MOZNOSTI = 0;

// zagotovo se da bolj elegantno pogledat ampak je kar je
bool isValid(bool** plosca, int n)
{
    for(int i = 0; i < n; i++)//vrstica
    {
        for(int j = 0; j < n; j++)//stolpec
        {
            if(plosca[i][j])
            {
                // preveri ce je katera v isti vrstici
                for(int v = 0; v < n; v++)
                {
                    if(plosca[i][v] && v != j)
                        return false;
                }
                // preveri ce je katera v istem stolpcu
                for(int s = 0; s < n; s++)
                {
                    if(plosca[s][j] && s != i)
                        return false;
                }
                
                // preverimo za diagonale
                int vsotaPozicije = i + j;
                
                for(int ii = 0; ii < n; ii++)
                {
                    for(int jj = 0; jj < n; jj++)
                    {
                        if(plosca[ii][jj] && !(ii == i && jj == j) && (_abs(ii,i)==_abs(jj,j)))
                            return false;
                    }
                }
            }
        }
    }
    
    return true;
}

void izpisi(bool** plosca, int n)
{
    for(int ii = 0; ii < n; ii++)
    {
        for(int jj = 0; jj < n; jj++)
        {
            printf("%c", plosca[jj][ii] ? 'X' : 'O');
        }
        printf("\n");
    }
    printf("\n");
}

void postavi(int n, int stolpec, bool** plosca)
{
    if(stolpec == n)
    {
        // preveri veljavnost
        if(isValid(plosca, n))
        {
            STEVILO_MOZNOSTI++;
           izpisi(plosca, n);
        }
        return;
    }
    
    for(int v = 0; v < n; v++)
    {
        plosca[v][stolpec] = true;
        // preveri veljavnost
        // ce je veljavno klici naprej rekurzijo
        if(isValid(plosca, n))
        {
            postavi(n, stolpec + 1, plosca);
        }
        
        plosca[v][stolpec] = false;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    bool** plosca = malloc(n * sizeof(bool*));
    for(int i = 0; i < n; i++)
        plosca[i] = malloc(n * sizeof(bool));
    
    
    postavi(n, 0, plosca);
    
    printf("%d\n", st);
    
    for(int i = 0; i < n; i++)
        free(plosca[i]);
    free(plosca);
    return 0;
}