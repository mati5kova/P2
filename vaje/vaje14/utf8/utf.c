#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	FILE* in = fopen(argv[1], "rb");
	if(in == NULL)
	{
		printf("Napaka pri branju datoteke %s\n", argv[1]);
		exit(1);
	}
	
	FILE* out = fopen(argv[2], "wb");
	if(out == NULL)
	{
		printf("Napaka pri odpiranju datoteke %s\n", argv[2]);
		exit(1);
	}
	
	while(1)
	{
		short zaIzpis;
		unsigned char bajt1;
		int stPrebranih = fread(&bajt1, sizeof(unsigned char), 1, in);
		if(stPrebranih == 0)
		{
			break;
		}
		
		
		if(bajt1 <= (1 << 7))
		{
			zaIzpis = bajt1;
		} else
		{
			unsigned char bajt2;
			fread(&bajt2, sizeof(unsigned char), 1, in);
			short ostanekB1 = (63 & bajt1);
			short ostanekB2 = (63 & bajt2);
			zaIzpis = (ostanekB1 << 6) + ostanekB2;
		}
		
		fwrite(&zaIzpis, sizeof(short), 1, out);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}