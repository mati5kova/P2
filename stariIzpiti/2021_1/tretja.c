#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int mnozica[] = {0, 9};

void izpisi(int* t, char* op, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%d", t[i]);
		if(i != len - 1)
			printf("%c", op[i]);
	}
	printf("\n");
}

void rek(int n, int* t, char* op, int len)
{
	if(len == n)
	{
		izpisi(t, op, len);
		return;
	}
	
	for(int i = mnozica[0]; i <= mnozica[1]; i++)
	{
		t[len] = i;
		
		// damo + vmes
		op[len] = '+';
		rek(n, t, op, len + 1);
		
		// damo - vmes
		// if stavek je zato da se rezultati ne podvajajo ker je dejanski op npr. =[+,+,+] za t=[0,0,0] (1 op preveč)
		//   -> zadnji (n-ti operator se itak ne izpiše zato lahko damo isti pogoj na katerega koli od +-)
		if(len != n - 1)
		{
			op[len] = '-';
			rek(n, t, op, len + 1);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int* t = malloc(n * sizeof(int));
	char* op = malloc(n * sizeof(char));

	rek(n, t, op, 0);

	free(t);
	free(op);
    return 0;
}

