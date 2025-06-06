#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isCrka(int c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void odstraniDuplikate(FILE *vhod, FILE *izhod) {
	int prev = EOF;
	int c;
	
	while((c = fgetc(vhod)) != EOF)
	{
		if(isCrka(c) && c == prev)
		{
			
		} else
		{
			fputc(c, izhod);
		}
		prev = c;
	}
}

int main(int argc, char *argv[])
{
    FILE* vhod = fopen(argv[1], "r");
    if (vhod == NULL) {
        printf("Napaka pri odpiranju vhodne datoteke");
        return 1;
    }

    FILE* izhod = fopen(argv[2], "w");
    if (izhod == NULL) {
        printf("Napaka pri odpiranju izhodne datoteke");
        fclose(vhod);
        return 1;
    }

    odstraniDuplikate(vhod, izhod);

    fclose(vhod);
    fclose(izhod);
    return 0;
}
