#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char* zdruzi(char** nizi, char* locilo) {
    // popravite / dopolnite ...
	char** p_nizi = nizi;
	
	int dolzinaLocila = strlen(locilo);
	int dolzinaVsehNizov = 0;
	int stNizov = 0;//koliko posameznih nizov je do kazalca NULL
	
	while(*p_nizi != NULL)
	{
		dolzinaVsehNizov += strlen(*p_nizi);
		stNizov++;
		p_nizi++;
	}
	p_nizi = nizi;

	//ce sta dva niza je med njima eno locilo (stNizov - 1)
	int alociranProstor = (stNizov-1) * dolzinaLocila + dolzinaVsehNizov + 1;
	
	char* t = malloc(alociranProstor * sizeof(char));	
	if(t == NULL) {return NULL;}
	
	int indeks = 0;
	while(*p_nizi != NULL)
	{
		for(int i = 0; i < strlen(*p_nizi); i++)
		{
			t[indeks] = (*p_nizi)[i];
			indeks++;
		}

		//zmanjsamo stevilo koliko nizov je se za zdruzit
		//pomembno za check da se ne da locila za zadnjim zdruzenim nizom 
		--stNizov;

		for(int i = 0; i < dolzinaLocila && stNizov != 0; i++)
		{
			t[indeks] = locilo[i];
			indeks++;
		}
		p_nizi++;
	}
	t[indeks] = '\0';

    return t;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje
    return 0;
}

#endif
