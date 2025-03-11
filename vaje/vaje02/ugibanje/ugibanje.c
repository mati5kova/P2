#include <stdio.h>

int sredina(int x,int y) {return (x+y)/2;}

int main()
{
	int sp, zg, ugib, i;
	scanf("%d",&sp);
	scanf("%d", &zg);
	ugib = sredina(sp, zg);

	while((i != 0))
	{
		scanf("%d", &i);

		if(i == 1)
			sp = ugib + 1;
		else if(i == -1)
			zg = ugib - 1;

		ugib = sredina(sp, zg);
	}

	if(sp > zg)
		printf("PROTISLOVJE\n");
	else if(sp == zg)
		printf("%d\n", ugib);
	else
		printf("%d %d\n", sp, zg);

	return 0;
}
