#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* og = fopen(argv[1], "rb");
	if(og == NULL)
	{
		printf("Napaka pri odpiranju %s\n", argv[1]);
		exit(1);
	}
	
	int w, h;
	
	int line = 0;
	while(1)
	{
		if(line == 3) break;
		if(line == 1)
		{
			fscanf(og, "%d %d", &w, &h);
		}
		
		
		char znak = fgetc(og);
		if(znak == '\n')
			line++;
	}
	
	FILE* novo = fopen(argv[2], "wa");
	if(novo == NULL)
	{
		printf("Napaka pri odpiranju %s\n", argv[1]);
		exit(1);
	}
	
	char buffer[25];
	sprintf(buffer, "P5\n%d %d\n255\n", w, h);
	
	fwrite(buffer, sizeof(buffer[0]), strlen(buffer), novo);
	
	for(int v = 0; v < h; v++)
	{
		for(int s = 0; s < w; s++)
		{
			int R, G, B;
			fread(&R, 1, 1, og);
			fread(&G, 1, 1, og);
			fread(&B, 1, 1, og);
			
			int pika = (int) ((30 * R + 59 * G + 11 * B) / 100);
			//printf("R:%d G:%d B:%d   pika:%d\n", R, G, B, pika);
			fwrite(&pika, 1, 1, novo);
		}
	}
	
	
	
	fclose(og);
	fclose(novo);
	return 0;
}