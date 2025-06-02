#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char vsebina[] = {0, 95, 0,
						   0, 0, 0,
						   66, 10, 0,
						   0, 0, 60,
						   0, 37, 0,
						   0, 205, 208,
						   0, 5, 0};
int t[] = {0, 0, 0};

int main()
{
	char vhod[21];
	int n;
	char izhod[21];
	
	scanf("%s\n%d\n%s", vhod, &n, izhod);	
	
	// ker ni vhodnih datotek
	FILE* g = fopen(vhod, "wb");
	if(g == NULL)
	{
		printf("Ustvarjanje binarne datoteke %s\n", vhod);
		exit(1);
	}
	for(int i = 0; i < n*3; i++)
	{
		fwrite(vsebina, sizeof(unsigned char), sizeof(vsebina)/sizeof(vsebina[0]), g);
	}
	fclose(g);
	
	
	FILE* f = fopen(vhod, "rb");
	if(f == NULL)
	{
		printf("Napak pri odpiranju %s\n", vhod);
		exit(1);
	}
	
	for(int i = 0; i < n; i++)
	{
		unsigned char r, g, b;
		fread(&r, 1, 1, f);
		fread(&g, 1, 1, f);
		fread(&b, 1, 1, f);
		//printf("%d %d %d\n", r, g, b);
		
		if(g == b && g == 0 && r > 0)
			t[0]++;
		else if(r == b && r == 0 && g > 0)
			t[1]++;
		else if(r == g && r == 0 && b > 0)
			t[2]++;
	}
	
	fclose(f);
	
	FILE* out = fopen(izhod, "w");
	if(out == NULL)
	{
		printf("Napak pri odpiranju %s\n", izhod);
		exit(1);
	}
	
	for(int i = 0; i < sizeof(t)/sizeof(t[0]); i++)
	{
		fprintf(out, "%d\n", t[i]);
	}
	
	fclose(out);
	
    return 0;
}

