#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 20

char** pretvori(char tabela[][N], int m)
{
	char** novo = malloc(m * sizeof(char*));
	
	for(int vrstica = 0; vrstica < m; vrstica++)
	{
		int dolzina = 1; // 1 zaradi '\0'
		for(int crka = 0; crka < N; crka++)
		{
			if(tabela[vrstica][crka] == '\0')
				break;
			dolzina++;
		}
		
		novo[vrstica] = malloc(dolzina * sizeof(char));
		strcpy(novo[vrstica], tabela[vrstica]);
	}
	return novo;
}

int main()
{
	char tabela[][N] = {
        "Hello",
        "World",
        "C",
        "**pretvori"
    };
    int m = sizeof(tabela) / sizeof(tabela[0]);

    
    char** kopije = pretvori(tabela, m);

    
    printf("Izpis kopij nizov:\n");
    for (int i = 0; i < m; i++) {
        printf("  kopije[%d] = \"%s\"\n", i, kopije[i]);
    }

    // cleanup
    for (int i = 0; i < m; i++) {
        free(kopije[i]);
    }
    free(kopije);
    return 0;
}

