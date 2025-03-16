#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, novoStevilo, i, k;
	scanf("%d", &n);
	
	int *tabela = (int*) malloc(n * sizeof(int));
	
	for(k = 0; k < n; k++)
	{
		scanf("%d", &novoStevilo);
		tabela[k] = novoStevilo;
	}
	
	/* O(n^2) -> timeoutajo testi
	int najboljsaVsota = tabela[0];
	for(i = 0; i < n; i++)
	{
		int delnaVsota = 0;
		for(k = i; k < n; k++)
		{
			delnaVsota += tabela[k];
			if(delnaVsota > najboljsaVsota)
			{
				najboljsaVsota = delnaVsota;
			}
		}
	}
	*/
	
	// O(n) - kadanov algoritem
	int trenutnaVsota = 0;
	int najboljsaVsota = tabela[0];
	
	for(i = 0; i < n; i++)
	{
		trenutnaVsota = max(tabela[i], trenutnaVsota + tabela[i]);
		najboljsaVsota = max(trenutnaVsota, najboljsaVsota);
	}
	
	printf("%d\n", najboljsaVsota);
	
	free(tabela);
	return 0;
}