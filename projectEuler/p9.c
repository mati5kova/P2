#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define ISKANA_VSOTA 1000

int main()
{
	bool najdeno = false;
	for(int c = 2; c < ISKANA_VSOTA && !najdeno; c++)
	{
		int cc = c * c;
		for(int a = 1; a < ISKANA_VSOTA && !najdeno; a++)
		{
			int aa = a * a;
			int bb = cc - aa;
			int sqbb = round(sqrt(bb));
			
			if(sqbb != 0 && sqbb * sqbb == bb && c + a + sqbb == ISKANA_VSOTA)
			{
				printf("%d + %d + %d = %d", a, sqbb, c, ISKANA_VSOTA);
				najdeno = true;
			}
			
		}
	}
	
	
	return 0;
}