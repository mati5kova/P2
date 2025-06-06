#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool rek(char* izraz, int n, int* indeks)
{
	char curr = izraz[*indeks];
	*indeks += 1;

	
	if(curr == 'F' || curr == 'T')
		return curr == 'F' ? false : true;
	
	if(curr == '&')
	{
		bool left = rek(izraz, n, indeks);
		bool right = rek(izraz, n, indeks);
		return (left && right);
	} else if(curr == '|')
	{
		bool left = rek(izraz, n, indeks);
		bool right = rek(izraz, n, indeks);
		return (left || right);
	} else if(curr == '!')
	{
		return !(rek(izraz, n, indeks));
	}
	
	return false; // failsafe
}

int main()
{
	char* izraz = malloc(1001 * sizeof(char));
	scanf("%s", izraz);
	
	int n = strlen(izraz);
	int i = 0;
	int* ptr_i = &i;
	
	bool valid = rek(izraz, n, ptr_i);
	putchar(valid ? 'T' : 'F');
	putchar('\n');
	
	free(izraz);
    return 0;
}

