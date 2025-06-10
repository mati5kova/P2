#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int _abs(int a, int b) 
{
    return a - b < 0 ? 0 - a + b : a - b;
}

bool veljavenSkok(int s0, int v0, int s1, int v1)
{
    if(_abs(s0, s1)*_abs(v0, v1) == 2)
        return true;
    return false;
}


// ni narejeno z datotekami ker se mi ni dalo, implementacija bi bila praktično ista
//  -> verjetno bi namesto getchar uporabil gets in se sprehodil po bufferju
int main()
{
    int n, p;
    scanf("%d %d\n", &n, &p);
    
    for(int v = 0; v < p; v++)
    {
        bool** t = malloc(n * sizeof(bool*));
        for(int i = 0; i < n; i++)
            t[i] = malloc(n * sizeof(bool));

        bool niPodvojitev = true;
        bool prvic = true;
        
        int prevStolpec;
        int prevVrstica;
        
        while(1)
        { 
            char stolpec_c = getchar();
            char vrstica_c = getchar();
            char separator_c = getchar();
            
            
            int stolpec = stolpec_c - 'a';
            int vrstica = atoi(&vrstica_c) - 1;
            
            
            if(t[vrstica][stolpec] == true)
                niPodvojitev = false;
            
            t[vrstica][stolpec] = true;
            
            if(prvic)
            {
                prvic = false;
                
            } else
            {
                if(!veljavenSkok(prevStolpec, prevVrstica, stolpec, vrstica))
                {
                    niPodvojitev = false;
                }
            }
            
            prevStolpec = stolpec;
            prevVrstica = vrstica;
            
            if(separator_c == '\n' || separator_c == EOF){
                break;
            }
        }
        
        // output
        printf("%d\n", niPodvojitev ? 1 : 0);

        for(int i = 0; i < n; i++)
            free(t[i]);
        free(t);
    }
    
    return 0;
}

