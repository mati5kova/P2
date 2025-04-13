#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DOLZINA_VHODNEGA_NIZA 44
#define MAX_DOLZINA_KONCNEGA_NIZA 101

void izpisiNiz(char* n)
{
	int i = 0;
	while(n[i] != '\0')
	{
		printf("%c", n[i]);
		i++;
	}
	printf("\n");
}

void podNiz(char** vhodniNizi, int stVhodnihNizov, int* dolzineVhodnihNizov, int indeks1, char* niz)
{
	if(indeks1 == stVhodnihNizov)
	{
		izpisiNiz(niz);
	} else
	{
		for(int i = 0; i < dolzineVhodnihNizov[indeks1]; i++)
		{
			char* tempNiz = calloc(MAX_DOLZINA_KONCNEGA_NIZA, sizeof(char));
			int k;
			for(k = 0; niz[k] != 0; k++)
			{
				tempNiz[k] = niz[k];
			}
			tempNiz[k] = vhodniNizi[indeks1][i];
			
			podNiz(vhodniNizi, stVhodnihNizov, dolzineVhodnihNizov, indeks1 + 1, tempNiz);
			
			free(tempNiz);
		}
	}
}

int main()
{
	int n; scanf("%d\n", &n);//treba \n da tudi to pobere in da program deluje pravilno

	/* za prvi (oz. test11.in) testni primer
	 * ['a', 'b', '\0', ...]
	 * ['c', 'd', 'e', '\0', ...]
	 * ['f', '\0', ...]
	 * ['g', 'h', '\0', ...]
	 */
	char** vhodniNizi = malloc(n * sizeof(char*));
	
	/* za prvi (oz. test11.in) testni primer
  	 * [2, 3, 1 ,2]
	 */
	int* dolzineVhodnihNizov = malloc(n * sizeof(int));
	
	char* niz = calloc(MAX_DOLZINA_KONCNEGA_NIZA, sizeof(char));
	
	for(int i = 0; i < n; i++)
	{
		vhodniNizi[i] = calloc(MAX_DOLZINA_VHODNEGA_NIZA, sizeof(char));
		char c;
		int k;
		for(k = 0; (c = getchar()) != '\n' && c != EOF; )
		{
			// to je samo zaradi test11.in spisanega v notepadu z windows CR LF
			// lahko bi samo odstranil carriage return ampak nej bo tako
			// 	da lahko napišeš svoje testne datoteke kjekoli
			if(c != '\r')
				vhodniNizi[i][k++] = c;
		}
		dolzineVhodnihNizov[i] = k;
	}
	
	podNiz(vhodniNizi, n, dolzineVhodnihNizov, 0, niz);
	
	for(int i = 0; i < n; i++) { free(vhodniNizi[i]); }
	free(niz);
	free(vhodniNizi);
	return 0;
}