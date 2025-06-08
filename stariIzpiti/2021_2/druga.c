#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char testni_podatki[] = {2, 15, 137, 128, 128};

int main(int argc, char* argv[])
{
	FILE* test_write = fopen(argv[1], "wb");
	if(test_write == NULL)
	{
		printf("Napaka pri odpiranju %s\n", argv[1]);
		exit(1);
	}
	fwrite(testni_podatki, sizeof(unsigned char), sizeof(testni_podatki)/sizeof(unsigned char), test_write);
	fclose(test_write);
	
	FILE* f = fopen(argv[1], "rb");
	if(f == NULL)
	{
		printf("Napaka pri branju %s\n", argv[1]);
		exit(1);
	}

	while(1)
	{
		unsigned char bajt1;
		int st = fread(&bajt1, sizeof(unsigned char), 1, f);
		if(st == 0)
		{
			break;
		}
		
		// če ima LSB==0 je to samostojno število zato ga pretovirmo in izpišemo
		if((bajt1 & 1) < 1)
		{
			bajt1 = bajt1 >> 1; // shiftamo eno v desno (se znebimo 0/1 ki je bil dodan v koraku 4)
			bajt1 = bajt1 & 127; // & 127 da izničimo morebitno nastalo vodilno enico zaradi >> 1
			printf("%d\n", bajt1);
		} else
		{
			unsigned char* t = malloc(100 * sizeof(unsigned char));
			t[0] = bajt1;
			int stBajtov = 1;
			
			while(1)
			{
				st = fread(&(t[stBajtov]), sizeof(unsigned char), 1, f);
				stBajtov++;
				if(st == 0 || (t[stBajtov - 1] & 1) < 1)
				{
					break;
				}
			}
			
			for(int i = 0; i < stBajtov; i++)
			{
				unsigned char currBajt = t[i];
				currBajt = currBajt >> 1;
				currBajt = currBajt & 127;
				t[i] = currBajt;
			}
			
			unsigned long long int stevilo = 0;
			for(int i = 0; i < stBajtov; i++)
			{
				unsigned char currBajt = t[i];
				stevilo = stevilo << 7;
				stevilo += currBajt;
			}
			
			printf("%llu\n", stevilo);
			
			free(t);
		}
	}


	fclose(f);
    return 0;
}

