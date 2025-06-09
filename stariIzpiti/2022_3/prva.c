#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char test_podatki[] = {76, 150, 28, 226, 104, 178};
int test_w = 3, test_h = 2;

int main(int argc, char* argv[])
{
	/* zacetek ustvarjanja testnega primera iz izpita*/
	FILE* test_write = fopen(argv[1], "wb");
	if(test_write == NULL)
	{
		printf("Napaka pri odpiranju\n");
		exit(1);
	}
	fprintf(test_write, "P5\n%d %d\n255\n", test_w, test_h);	
	fwrite(test_podatki, sizeof(unsigned char), sizeof(test_podatki)/sizeof(test_podatki[0]), test_write);
	
	fclose(test_write);
	/* konec ustvarjanja testnega primera iz izpita*/
	
	int prag = atoi(argv[2]);

	FILE* f = fopen(argv[1], "rb");
	if(f == NULL)
	{
		printf("Napaka pri branju\n");
		exit(1);
	}
	int w, h;
	fscanf(f, "P5\n%d %d\n255\n", &w, &h);
	
	FILE* out = fopen(argv[3], "wb");
	if(out == NULL)
	{
		printf("Napaka pri odpiranju\n");
		fclose(f);
		exit(1);
	}
	fprintf(out, "P5\n%d %d\n255\n", w, h);

	unsigned char _255 = 255;
	unsigned char _0 = 0;
	while(1)
	{
		unsigned char bajt;
		short st = fread(&bajt, 1, 1, f);
		if(st == 0) break;
		
		if(bajt >= prag)
		{
			fwrite(&_255, 1, 1, out);
		} else
		{
			fwrite(&_0, 1, 1, out);
		}
	}
	fclose(out);
	fclose(f);
    return 0;
}

