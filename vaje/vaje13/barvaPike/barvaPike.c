#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char* ime_dat = argv[1];
	int vrstica = atoi(argv[2]);
	int stolpec = atoi(argv[3]);
	
	FILE* f;
	f = fopen(ime_dat, "rb");
	if(f == NULL)
	{
		printf("Napaka pri branju datoteke %s\n", ime_dat);
		exit(1);
	}
	
	int line = 0;
	int w, h;
	while(1)
	{
		if(line == 3) break;
		if(line == 1)
		{
			fscanf(f, "%d %d", &w, &h);
		}
			
		char znak = fgetc(f);
		if(znak == '\n')
			line++;
	}
	
	int R, G, B;
	
	fseek(f, ((vrstica*w) + stolpec) * 3, SEEK_CUR);
	
	fread(&R, 1, 1, f);
	fread(&G, 1, 1, f);
	fread(&B, 1, 1, f);
	
	printf("%d %d %d\n", R, G, B);
	
	fclose(f);
	return 0;
}
