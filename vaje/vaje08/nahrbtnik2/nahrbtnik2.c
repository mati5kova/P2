#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

int preglejNahrbtnik(int vol, int st, int indeks, int* prostornine, int* cene, int*** memo, int k)
{
	if(indeks == st)
		return 0;
	if(vol < 0)
		return -1000000;
	
	int memoVal = memo[indeks][vol][k];
	if(memoVal != -1)
		return memoVal;
	
	int vzamemo = 0;
    if (vol >= prostornine[indeks]) {
		
		int novPredmet = prostornine[indeks];
		if(novPredmet % 2 != 0)
		{
			if(k > 0)
				vzamemo = cene[indeks] + preglejNahrbtnik(vol - novPredmet, st, indeks + 1, prostornine, cene, memo, k - 1);
		} else
		{
			vzamemo = cene[indeks] + preglejNahrbtnik(vol - novPredmet, st, indeks + 1, prostornine, cene, memo, k);
		}
    }

    int neVzamemo = preglejNahrbtnik(vol, st, indeks + 1, prostornine, cene, memo, k);

    memo[indeks][vol][k] = max(vzamemo, neVzamemo);
	
    return memo[indeks][vol][k];
}

int main()
{
	int prostornina, stPredmetov, liho;
	scanf("%d%d%d", &prostornina, &stPredmetov, &liho);
	
	int* prostornine = malloc(stPredmetov * sizeof(int));
	int* cene = malloc(stPredmetov * sizeof(int));
	int*** memo = malloc((stPredmetov + 1) * sizeof(int**));
	
	for(int i = 0; i < stPredmetov; i++)
	{
		scanf("%d", &prostornine[i]);
	}
	for(int i = 0; i < stPredmetov; i++)
	{
		scanf("%d", &cene[i]);
	}
	
	for(int i = 0; i <= stPredmetov; i++)
	{
		memo[i] = malloc((prostornina + 1) * sizeof(int*));
		for(int k = 0; k <= prostornina; k++)
		{
			memo[i][k] = malloc((liho + 1) * sizeof(int));
			for(int j = 0; j <= liho; j++)
				memo[i][k][j] = -1;
		}
	}
	
	int najvecjaSkupnaCena = preglejNahrbtnik(prostornina, stPredmetov, 0, prostornine, cene, memo, liho);
	printf("%d\n", najvecjaSkupnaCena);
	
	for(int i = 0; i <= stPredmetov; i++)
	{
		for(int k = 0; k <= prostornina; k++)
			free(memo[i][k]);
		free(memo[i]);
	}

	free(memo);
	free(prostornine);
	free(cene);
	return 0;
}