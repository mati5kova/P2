#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Pika {
	int stevilo;
	int R, G, B;
} Pika;

int main()
{
	char dat[21];
	scanf("%s", dat);
	
	FILE* f = fopen(dat, "rb");
	if(f == NULL)
	{
		printf("Napaka pri odpiranju datoteke %s\n", dat);
		exit(1);
	}
	
	for(int i = 0; i < 3; i++)
		fgetc(f);
	
	int w, h;
	fscanf(f, "%d %d\n", &w, &h);
	
	for(int i = 0; i < 4; i++)
		fgetc(f);
	
	
	int stPik = 0;
	Pika* t = (Pika*) calloc(w*h, sizeof(Pika));
	
	
	for(int v = 0; v < h; v++)
	{
		for(int s = 0; s < w; s++)
		{
			bool zapisano = false;
			
			int R, G, B;
			fread(&R, 1, 1, f);
			fread(&G, 1, 1, f);
			fread(&B, 1, 1, f);
			
			for(int i = 0; i < stPik && !zapisano; i++)
			{
				if(t[i].R == R && t[i].G == G && t[i].B == B)
				{
					t[i].stevilo += 1;
					zapisano = true;
				}
			}
			
			if(!zapisano)
			{
				t[stPik].R = R;
				t[stPik].G = G;
				t[stPik].B = B;
				t[stPik].stevilo = 1;
				stPik++;
			}
			
			//printf("(%d %d %d)\n", R, G, B);
		}
	}
	
	printf("stevilo razlicnih barv: %d\n", stPik);	
	
	int currMaxNum = 0;
	for(int i = 0; i < stPik; i++)
	{
		if(t[i].stevilo > currMaxNum)
			currMaxNum = t[i].stevilo;
		
		//printf("(%d %d %d), %d\n", t[i].R, t[i].G, t[i].B, t[i].stevilo);
	}
	printf("stevilo pik v najpogostejsi barvi: %d\n", currMaxNum);
	
	
	free(t);
	
	fclose(f);
	return 0;
}