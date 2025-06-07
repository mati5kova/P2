#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char test_01[] = {27, 201, 254, 27, 27, 201, 201, 66, 201, 27};

int main(int argc, char* argv[])
{
	FILE* test_write = fopen(argv[1], "wb");
	if(test_write == NULL)
	{
		printf("Napaka pri branju %s\n", argv[1]);
		exit(1);
	}
	fwrite(test_01, 1, 10, test_write);
	fclose(test_write);
	
	
	FILE* in = fopen(argv[1], "rb");
	if(in == NULL)
	{
		printf("Napaka pri branju %s\n", argv[1]);
		exit(1);
	}
	
	FILE* out = fopen(argv[2], "wb");
	if(out == NULL)
	{
		printf("Napaka pri branju %s\n", argv[2]);
		exit(1);
	}
	
	unsigned char prejsnjaVrednost_10 = 0;
	bool pisiPrejsnjo = false;

	while(1)
	{
		
		unsigned char b1;
		int i1 = fread(&b1, 1, 1, in);
		if(i1 == 0)
		{
			fwrite(&prejsnjaVrednost_10, 1, 1, out);
			break;
		}

		
		if(b1 == 201 && prejsnjaVrednost_10 == 27)
		{
			fwrite(&b1, 1, 1, out);
			pisiPrejsnjo = false;
		} else 
		{
			if(pisiPrejsnjo == true)
				fwrite(&prejsnjaVrednost_10, 1, 1, out);
			pisiPrejsnjo = true;
		}
		
		prejsnjaVrednost_10 = b1;
	}
	

	fclose(in);
	fclose(out);
    return 0;
}

