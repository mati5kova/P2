#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int n, int steviloKorakov, int steviloVzponov, int steviloSpustov, int* hrib, int visina)
{
	int stevilo = 0;
	
	if(steviloVzponov > n/2 || steviloSpustov > n/2 || visina < 0)
	{
		// kršimo pogoje
		return 0;
	}

	
	if(steviloKorakov == n)
	{
		for(int i = 0; i <= n; i++)
		{
			printf("%d ", hrib[i]);
		}
		printf("\n");
		
		return 1;	
	}
	
	// naredimo vzpon
	hrib[steviloKorakov + 1] = visina + 1;
	stevilo += rek(n, steviloKorakov + 1, steviloVzponov + 1, steviloSpustov, hrib, visina + 1);
	
	// naredimo spust
	hrib[steviloKorakov + 1] = visina - 1;
	stevilo += rek(n, steviloKorakov + 1, steviloVzponov, steviloSpustov + 1, hrib, visina - 1);
	
	return stevilo;
}


int main()
{
	int n;
	scanf("%d", &n);
	
	int hrib[n+1];
	hrib[0] = 0;
	int stevilo = rek(n, 0, 0, 0, hrib, 0);
	
	printf("%d\n", stevilo);
	
    return 0;
}

