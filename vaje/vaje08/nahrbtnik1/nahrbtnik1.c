#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

int preglejNahrbtnik(int vol, int st, int indeks, int* prostornine, int* cene, int** memo)
{
	if(indeks == st)
		return 0;
	if(vol < 0)
		return -1000000;
	
	int memoVal = memo[indeks][vol];
	if(memoVal != -1)
		return memoVal;
	
	int vzamemo = 0;
    if (vol >= prostornine[indeks]) {
        vzamemo = cene[indeks] + preglejNahrbtnik(vol - prostornine[indeks], st, indeks + 1, prostornine, cene, memo);
    }

    int neVzamemo = preglejNahrbtnik(vol, st, indeks + 1, prostornine, cene, memo);

    memo[indeks][vol] = max(vzamemo, neVzamemo);
	
    return memo[indeks][vol];
}

int main()
{
	int prostornina, stPredmetov;
	scanf("%d%d", &prostornina, &stPredmetov);
	
	int* prostornine = malloc(stPredmetov * sizeof(int));
	int* cene = malloc(stPredmetov * sizeof(int));
	int** memo = malloc((stPredmetov + 1) * sizeof(int*));
	
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
		memo[i] = malloc((prostornina + 1) * sizeof(int));
		for(int k = 0; k <= prostornina; k++)
		{
			memo[i][k] = -1;
		}
	}
	
	int najvecjaSkupnaCena = preglejNahrbtnik(prostornina, stPredmetov, 0, prostornine, cene, memo);
	printf("%d\n", najvecjaSkupnaCena);
	
	for(int i = 0; i <= stPredmetov; i++)
		free(memo[i]);
	free(memo);
	free(prostornine);
	free(cene);
	return 0;
}