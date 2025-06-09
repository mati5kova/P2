#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 1 - pobarvano
// 0 - prazno
char izracunajBarvo(int v, int s)
{	
	return (v & ~s) == 0; // <- chatgpt ahh rešitev

	while (v > 0 || s > 0) {
		if ((v % 2 == 1) && (s % 2 == 0)) return 0;
		v /= 2;
		s /= 2;
	}
	return 1;
}

int main()
{
	int n, v0, s0, h, w;
	scanf("%d %d %d %d %d", &n, &v0, &s0, &h, &w);
	
	int dimenzija = 1 << n;
	char** t = malloc(h * sizeof(char*));
	for(int i = 0; i < h; i++)
		t[i] = malloc(w * sizeof(char));
	
	unsigned long long int counter = 0;
	
	for(int v = 0; v < dimenzija; v++)
	{
		for(int s = 0; s < dimenzija; s++)
		{
			char stanje = izracunajBarvo(v, s);
			if(stanje == 1)
				counter++;
			
			if(v >= v0 && v < (v0 + h) && s >= s0 && s < (s0 + w))
			{
				t[v-v0][s-s0] = stanje == 1 ? '*' : '-';
			}
		}
	}
	printf("%llu\n", counter);
	
	for(int v = 0; v < h; v++)
	{
		bool zapisalVrstico = false;
		for(int s = 0; s < w; s++)
		{
			printf("%c", t[v][s]);
			
		}
		printf("\n");
	}
	
	for(int i = 0; i < h; i++)
		free(t[i]);
	free(t);

    return 0;
}

