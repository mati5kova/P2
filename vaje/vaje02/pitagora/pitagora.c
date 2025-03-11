#include <stdio.h>
#include <math.h>

int main() 
{
	int m, n, a, b, c, counter = 0;
	scanf("%d", &m);
	scanf("%d", &n);
		
	for(c = m; c <= n; ++c)
	{
		int cc = c * c;
		
		for(a = 1; a <= c; ++a)
		{
			int aa = a * a;
			int bb = cc - aa;
			int sqb = round(sqrt(bb));
			
			if(pow(sqb, 2) == bb && bb != 0)
			{
				counter++;
				a = sqb;
			}
		}
	}
	printf("%d\n", counter);
}