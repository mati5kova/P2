#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char testni_podatki[] = {42, 128, 0, 255};

int main(int argc, char* argv[])
{
	FILE* test_write = fopen(argv[1], "wb");
	if(test_write == NULL)
	{
		printf("Napaka pri odpiranju %s\n", argv[1]);
		exit(1);
	}
	fwrite(testni_podatki, sizeof(unsigned char), sizeof(testni_podatki)/sizeof(testni_podatki[0]), test_write);
	fclose(test_write);
	
	FILE* f = fopen(argv[1], "rb");
	if(f == NULL)
	{
		printf("Napaka pri branju %s\n", argv[1]);
		exit(1);
	}
	
	int counter = 0;
	while(1)
	{
		unsigned char bajt;
		int st = fread(&bajt, 1, 1, f);
		if(st == 0) break;
		
		for(int i = 0; i < 8; i++)
		{
			unsigned char stZaPrimerjavo = 1 << i;
			unsigned char rez = bajt & stZaPrimerjavo;
			if(rez > 0)
				counter++;
		}
	}
	
	printf("%d\n", counter);
	
	fclose(f);
    return 0;
}

