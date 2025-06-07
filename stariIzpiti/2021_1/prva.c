#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

long long int l = 1234L; // 8B
short int s = 1; // 2B


int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Napiši vhod oblike: <./izvršljiv-program> <imebinarne-datoteke.bin> <0/1: 0-naredi short; 1-naredi long>\n");
		exit(1);
	}

	FILE* test_write = fopen(argv[1], "wb");
	if(test_write == NULL)
	{
		printf("Napaka pri odpiranju %s\n", argv[1]);
		exit(1);
	}

	fwrite(atoi(argv[2]) == 0 ? (void*)(&s) : (void*)(&l), atoi(argv[2]) == 0 ? sizeof(short int) : sizeof(long long int), 1, test_write);

	fclose(test_write);

	FILE* in = fopen(argv[1], "rb");
	if(in == NULL)
	{
		printf("Napaka pri branju %s\n", argv[1]);
		exit(1);
	}

	int counter = 0;
	while(1)
	{
		char bajt;
		int prebrano = fread(&bajt, 1, 1, in);
		if(prebrano == 0)
			break;

		counter += prebrano;
	}

	printf("(0-short, 1-long): %d\n", counter > 2 ? 1 : 0);

	fclose(in);

    return 0;
}

