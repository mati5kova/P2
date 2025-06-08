#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* in = fopen(argv[1], "r");
	if(in == NULL)
	{
		printf("Napaka pri odpiranju %s\n", argv[1]);
		exit(1);
	}
	
	int stClenov = 0;
	while(1)
	{
		int st;
		int p = fscanf(in, "%d", &st);
		if(p == EOF) break;
		stClenov++;
	}
	rewind(in);
	
	int* t = malloc(stClenov * sizeof(int));
	
	for(int i = 0; i < stClenov; i++)
	{
		int p = fscanf(in, "%d", &(t[i]));
	}
	
	int* a = malloc(stClenov * sizeof(int));
	a[0] = t[0]; // a1
	int indeks = 1;

	int sumStevilDoIndeksa = t[0];
	while(1)
	{
		int temp = sumStevilDoIndeksa;
		if(temp >= stClenov)
		{
			break;
		} else
		{
			a[indeks] = t[temp];
			sumStevilDoIndeksa += t[temp];
		}
		indeks++;
	}
	
	FILE* out = fopen(argv[2], "w");
	if(out == NULL)
	{
		printf("Napaka pri odpiranju %s\n", argv[2]);
		exit(1);
	}
	
	for(int i = 0; i < indeks; i++)
	{
		fprintf(out, "%d\n", a[i]);
	}
	
	
	fclose(in);
	fclose(out);
	free(t);
	free(a);
    return 0;
}

