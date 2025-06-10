#include <stdio.h>

int rekstrlen(char* niz)
{
	if(niz[0] == '\0')
		return 0;
	return 1 + rekstrlen(&(niz[1]));
}

int main()
{
	char niz[] = "programiranje";
	
	int dolzina = rekstrlen(niz);
	printf("dolzina: [%d]\n", dolzina);
	
	return 0;
}