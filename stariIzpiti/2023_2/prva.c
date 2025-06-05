#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char vhodni_podatki[] = {171, 171, 171, 213, 57, 57, 57, 213, 213, 171};

int main(int argc, char* argv[])
{
	FILE* test_write = fopen(argv[1], "wb");
	if(test_write == NULL)
	{
		printf("Napaka pri odpiranju daoteke %s\n", argv[1]);
		exit(1);
	}	
	fwrite(vhodni_podatki, sizeof(unsigned char), sizeof(vhodni_podatki)/sizeof(unsigned char), test_write);
	fclose(test_write);
	
	FILE* f = fopen(argv[1], "rb");
	if(f == NULL)
	{
		printf("Napaka pri odpiranju daoteke %s\n", argv[1]);
		exit(1);
	}
	FILE* out = fopen(argv[2], "wb");
	if(out == NULL)
	{
		printf("Napaka pri odpiranju daoteke %s\n", argv[2]);
		exit(1);
	}
	
	unsigned char prejsnji;
	bool prvic = true;
	while(1)
	{
		unsigned char bajt;
		int stPrebranih = fread(&bajt, sizeof(unsigned char), 1, f);
		if(stPrebranih == 0)
		{
			fwrite(&prejsnji, sizeof(unsigned char), 1, out);
			break;
		}
		
		if(prvic)
		{
			prejsnji = bajt;
			prvic = false;
			continue;
		}
		
		if(bajt != prejsnji)
		{
			fwrite(&prejsnji, sizeof(unsigned char), 1, out);
		} 
		prejsnji = bajt;
	}
	
	fclose(f);
	fclose(out);
    return 0;
}

