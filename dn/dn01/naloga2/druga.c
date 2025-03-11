#include <stdio.h>
#include <stdbool.h>

int beri()
{
	char c;
	int num = 0;
	bool negativno = false;


	while((c = getchar()) != EOF && c != ' ' && c != '\n') 
	{

		if(c == '-') 
		{
			negativno = true;
			c = getchar();
		}

		if(c >= '0' && c <= '1')
		{
			num = num * 2 + (c - '0');
		}
	}

	if(negativno)
		return -num;

	return num;

}

int logaritem2(int n)
{
	int i, k;
	
	for(i = 0; i < n; ++i)
	{
		int rez = 1;
		for(k = 0; k < i; ++k)
		{
			rez *= 2;
		}
		if(rez >= n)
			return i;
	}
	
}

void izpisi(int n) 
{
	if(n / 10 > 0)
		izpisi(n / 10);
	putchar(n % 10 + '0');
}

int main()
{

	int desetisko = beri();
	int log = logaritem2(desetisko);
	izpisi(log);
	
	//putchar('\n');
	return 0;
}

