#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int najdiGlobino(int** drevo, int node, int trenutnaGlobina)
{
	if(drevo[node][0] == drevo[node][1])
	{
		return trenutnaGlobina;
	}
	
	int leviOtrok = drevo[node][0];
	int desniOtrok = drevo[node][1];
	
	//preveri globino od otroka naprej (ce ni enak -1(torej ne obstaja in je nadaljna globina v tisto smer enaka 0))
	int globinaLevo = leviOtrok != -1 ? najdiGlobino(drevo, leviOtrok, trenutnaGlobina + 1) : 0;
	int globinaDesno = desniOtrok != -1 ? najdiGlobino(drevo, desniOtrok, trenutnaGlobina + 1) : 0;
	
	return max(globinaLevo, globinaDesno);
}

int main()
{
	int n;
	scanf("%d", &n);
	int** drevo = calloc(n, sizeof(int*));
	
	for(int i = 0; i < n; i++)
	{
		int levo, desno;
		scanf("%d%d", &levo, &desno);
		
		drevo[i] = calloc(2, sizeof(int));
		drevo[i][0] = levo;
		drevo[i][1] = desno;
	}
	
	int globina = najdiGlobino(drevo, 0, 0);
	printf("%d\n", globina);
	
	for(int i = 0; i < n; i++)
	{
		free(drevo[i]);
	}
	free(drevo);
	return 0;
}