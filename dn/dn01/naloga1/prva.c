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

		if(c >= '0' && c <= '9')
		{
			num = num * 10 + (c - '0');
		}
	}

	if(negativno)
		return -num;

	return num;

}

void izpisi(int n)
{
	if(n < 0)
    {
        putchar('-');
		n = -n;
    }

    if(n / 10 > 0)
    {
        izpisi(n / 10);
    }
	putchar(n % 10 + '0');
}

int main()
{
	int prvo = beri();
	int drugo = beri();
	
	izpisi(prvo + drugo);
	putchar('\n');
	
	return 0;
}
