#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char decToHexVector[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char* decToHex(unsigned char num)
{
	char* hex = malloc(3 * sizeof(unsigned char));
	
	hex[0] = decToHexVector[num / 16];
	hex[1] = decToHexVector[num % 16];
	hex[2] = '\0';
	
	return hex;
}

int main()
{
	char in[21];
	char out[21];
	int stB;
	scanf("%s\n%d\n%s", in, &stB, out);
	
	unsigned char test[6] = {'I', 'z', 'p', 'i', 't', '\n'};
	
	FILE* write_test = fopen(in, "wb");
	if(write_test == NULL)
	{
		printf("Napaka pri odpiranju %s\n", in);
		exit(1);
	}
	fwrite(test, sizeof(unsigned char), sizeof(test)/sizeof(test[0]), write_test);
	
	fclose(write_test);
	
	FILE* f = fopen(in, "rb");
	if(write_test == NULL)
	{
		printf("Napaka pri odpiranju %s\n", in);
		exit(1);
	}
	
	for(int i = 0; i < stB; i++)
	{
		unsigned char b;
		fread(&b, 1, 1, f);
		
		char* ret = decToHex(b);
		printf("%s\n", ret);
		
		free(ret);
	}
	
	fclose(f);
	
    return 0;
}

