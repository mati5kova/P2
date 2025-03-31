
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
	int counter = 0;
	for(int i = 0; niz[i] != '\0'; i++)
		counter += (niz[i] == znak) ? 1 : 0;
	
    return counter;
}

char* kopirajDoZnaka(char* niz, char znak) {
	int dolzina = 1; //'\0'
	for(int i = 0; niz[i] != znak && niz[i] != '\0'; i++)
	{
		dolzina++;
	}
	char* kopija = malloc(dolzina * sizeof(char));
	
	for(int i = 0; i < (dolzina - 1); i++)
	{
		kopija[i] = niz[i];
	}
	kopija[dolzina - 1] = '\0';

	return kopija;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
	int steviloOdsekov = steviloZnakov(niz, locilo) + 1;
	*stOdsekov = steviloOdsekov;
	
	char** tabela = malloc(steviloOdsekov * sizeof(char*));
	
	//zamik od zacetka niza
	int offset = 0;
	for(int i = 0; i < steviloOdsekov; i++)
	{
		tabela[i] = kopirajDoZnaka(&niz[offset], locilo);
		offset += strlen(tabela[i]) + 1;
	}

    return tabela;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
	char beseda[] = "program";
	printf("%d\n", steviloZnakov(beseda, 'r'));//2
	
    return 0;
}

#endif
