#include <stdio.h>
#include <stdlib.h>

/* tako izgleda int** t
 * v tabeli velikosti so zapisane velikosti posameznega nivoja (velikosti[2] == 4)
 *    -> bilo je potrebno v prejsnji implementaciji
 *
 *
 * 7
 * 2 3
 * 0 1 9 8
 * 5 4 6 3 7 1 8 6
 * for(int i = 0; i < k; i++)
 * {
 * 		for(int j = 0; j < velikosti[i]; j++)
 * 			printf("%d ", t[i][j]);
 * 		printf("\n");
 * }
*/
void izpisi(int** t, int vrstica, int indeks, int k)
{
	if(vrstica >= k) return;
	
	printf("%d", t[vrstica][indeks]);
	
	izpisi(t, vrstica + 1, indeks*2, k); // izpisi levo pod drevo
	izpisi(t, vrstica + 1, indeks*2 + 1, k); // izisi desno pod drevo
}

int main()
{
	int k; scanf("%d\n", &k);

	int* velikosti = malloc(k * sizeof(int)); // ni potrebno
	int** t = malloc(k * sizeof(int*));
	
	
	int stElementov = 1;
	for(int i = 0; i <= k; i++)
	{
		if(i != k) // v t[ko je i == k] ne vpisujemo vec, treba samo za pravilno potenciranje 
		{
			velikosti[i] = stElementov;
			t[i] = malloc(stElementov * sizeof(int));
			
			for(int j = 0; j < stElementov; j++)
				scanf("%d", &(t[i][j]));			
		}
		
		stElementov *= 2;
	}	

	izpisi(t, 0, 0, k);
	printf("\n");
	
	// cleanup
	free(velikosti);
	for(int i = 0; i < k; i++)
		free(t[i]);
	free(t);
	
	return 0;
}