#include <stdio.h>
#include <stdlib.h>

#define STELEMENTOV 100 //92
#define LIMITA 10000000000000000000LLU

int main()
{
	
	unsigned long long *ptabela = malloc(STELEMENTOV * sizeof(unsigned long long));
	ptabela[0] = ptabela[1] = 1;
	printf("1\n1\n");
	
	for(unsigned long long i = 2; i < STELEMENTOV; i++)
	{
		if (ptabela[i - 1] > LIMITA - ptabela[i - 2]) {
			break;
		}
		ptabela[i] = ptabela[i - 1] + ptabela[i - 2];
		printf("%llu\n", ptabela[i]);
	}	
	
	free(ptabela);
	return 0;
}