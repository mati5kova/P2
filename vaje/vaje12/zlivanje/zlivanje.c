#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; scanf("%d", &n);

	char izhod[101];
	int* t = calloc(1000000, sizeof(int));

	int currMax = 0;

	for(int i = 0; i < n; i++)
	{
		char dat[101];
		scanf("%s", dat);
		
		FILE* f;
		f = fopen(dat, "r");
		if(f == NULL)
		{
			printf("Napaka pri odpiranju datoteke '%s'\n", dat);
			exit(1);
		}
		
		int st;
		while(fscanf(f, "%d", &st) != EOF)
		{
			t[st]++;
			if(st > currMax)
				currMax = st;
		}
	
		fclose(f);
	}
	scanf("%s", izhod);
	
	FILE* f;
	f = fopen(izhod, "w");
	if(f == NULL)
	{
		printf("Napaka pri odpiranju datoteke '%s'\n", izhod);
		exit(1);
	}
	
	for(int i = 0; i <= currMax; i++)
	{
		if(t[i] == 0) continue;
		for(int k = 0; k < t[i]; k++)
			fprintf(f, "%d\n", i);
	}
	
	fclose(f);
	free(t);
	
	return 0;
}