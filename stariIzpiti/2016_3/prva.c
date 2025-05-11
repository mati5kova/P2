#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

bool jePrastevilo(int a)
{
	if(a < 2)
		return false;
	for(int i = 2; i*i <= a; i++)
		if(a % i == 0)
			return false;
	
	return true;
}

int main()
{
	int n, k; scanf("%d %d", &n, &k);
	
	while(1)
	{
		n++;
		if(jePrastevilo(n))
		{
			k--;
			if(k == 0)
			{
				printf("%d\n", n);
				break;
			}
		}
	}
	
	return 0;
}