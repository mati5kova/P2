#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * nimam originalnih .h datotek
 */
 
unsigned char* preberi(char* imeDat, int* sirina, int* visina, int* stBajtov)
{
	FILE* f = fopen(imeDat, "rb");
	if(f == NULL)
	{
		printf("Napaka pri branju datoteke %s\n", imeDat);
		exit(1);
	}
	
	char znak;
	
	while((znak = fgetc(f)) != '\n') {}
	
	int w, h;
	fscanf(f, "%d %d", &w, &h);
	while((znak = fgetc(f)) != '\n') {}
	while((znak = fgetc(f)) != '\n') {}
	
	
	*sirina = w;
	*visina = h;
	*stBajtov = w * h * 3;
	
	char* t = malloc((*stBajtov + 1) * sizeof(char));
	
	for(int i = 0; i < *stBajtov; i++)
	{
		unsigned char k;
		fread(&k, 1, 1, f);

		//printf("%d\n", k);

		t[i] = k;
	}
	
	t[*stBajtov] = '\0';
	
	fclose(f);
	return t;
}

int sivina(unsigned char* pike, int sirina, int visina, int vrstica, int stolpec)
{
	int R = pike[3 * vrstica * sirina + 3 * stolpec];
	int G = pike[3 * vrstica * sirina + 3 * stolpec + 1];
	int B = pike[3 * vrstica * sirina + 3 * stolpec + 2];
	
	return (int) ((R + G + B) / 3);
}

int main(int argc, char* argv[])
{
	int sirina, visina, stBajtov;
	
	unsigned char* x = preberi(argv[1], &sirina, &visina, &stBajtov);
	
	printf("sirina: %d\nvisina: %d\nstBajtov: %d\n", sirina, visina, stBajtov);
	
	for(int i = 0; i < stBajtov; i++)
	{
		printf("%c", x[i]);
	} 
	printf("\n");
	
	printf("sivina: %d\n", sivina(x, sirina, visina, 1, 0));
	
	free(x);
	return 0;
}