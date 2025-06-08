#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isValid(char* out, int len)
{
	bool hasLowerCase = false;
	bool hasUpperCase = false;
	bool hasDigit = false;
	
	for(int i = 0; i < len; i++)
	{
		char curr = out[i];
		if(isdigit(curr))
			hasDigit = true;
		if(islower(curr))
			hasLowerCase = true;
		if(isupper(curr))
			hasUpperCase = true;
	}
	
	return hasLowerCase && hasUpperCase && hasDigit;
}

void rek(int d, char* s, int n, char* out, int len)
{
	if(len == n)
	{
		if(isValid(out, len))
		{
			printf("%s\n", out);
		}
		return;
	}
	
	for(int i = 0; i < d; i++)
	{
		out[len] = s[i];
		rek(d, s, n, out, len + 1);
	}
	
}

int main()
{
	int d, n;
	char s[50];
	scanf("%d %s %d", &d, s, &n);
	
	char out[n+1];
	out[n] = '\0';
	
	rek(d, s, n, out, 0);
	
    return 0;
}

