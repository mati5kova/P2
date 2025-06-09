#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s, int d, char* out, int lenOut)
{
	
	for(int i = 0; i < d; i++)
	{
		int count = 0;
		for(int k = 0; k < lenOut; k++)
		{
			if(out[k] == s[i])
				count++;
		}
		if(count > 3)
			return false;
	}
	
	return true;
}

void rek(int d, char* s, int n, char* out, int lenOut)
{
	if(lenOut == n)
	{
		if(isValid(s, d, out, lenOut))
		{
			printf("%s\n", out);
		}
		return;
	}
	
	for(int i = 0; i < d; i++)
	{
		out[lenOut] = s[i];
		rek(d, s, n, out, lenOut + 1);
	}
}

int main()
{
	int d, n;
	char s[d];
	scanf("%d %s %d", &d, s, &n);
	
	char* out = malloc(n * sizeof(char));
	
	rek(d, s, n, out, 0);
	
	free(out);
    return 0;
}

