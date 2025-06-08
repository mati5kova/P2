#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_D 10000

int sestEj(char* niz)
{
	int len = strlen(niz);

	char** t = malloc(MAX_D / 3 * sizeof(char));
	int globalniTIndeks = 0;
	
	int indeks = 0;
	while(indeks < len)
	{
		if(niz[indeks] == 'E')
		{
			t[globalniTIndeks] = calloc(4, sizeof(char));
			bool zeZapisalStevilo = false;
			
			for(int i = 0; i < 4; i++)
			{
				indeks++;
				if(indeks >= len) { break; }
				
				char curr = niz[indeks];
				if(i == 0)
				{
					if('0' <= curr || curr <= '9')
						zeZapisalStevilo = true;
				}
				if(curr == 'E') 
				{
					break;
				}
				
				if('0' > curr && curr > '9' && curr != '_' && zeZapisalStevilo)
				{
					break;
				}
				t[globalniTIndeks][i] = curr;
			}
			
			globalniTIndeks++;
		}
		
		indeks++;
	}
	
	int vsota = 0;
	
	for(int i = 0; i < globalniTIndeks; i++)
	{
		char* currPossible = t[i];
		bool valid = true;
		
		for(int i = 0; i < 4 && valid; i++)
		{
			char curr = currPossible[i];
			if(i == 0 && !('1' <= curr && curr <= '9'))
				valid = false;
			if(i != 3 && !('0' <= curr && curr <= '9'))
				valid = false;
			if(i == 3 && curr != '_')
				valid = false;
		}
		
		if(valid)
		{
			vsota += atoi(currPossible);
		}
		
	}
	
	printf("%d\n", vsota);
	
	for(int i = 0; i  < globalniTIndeks; i++)
		free(t[i]);
	free(t);
	
	return 0;
}

int main()
{
	char* niz = malloc(MAX_D * sizeof(char));
	scanf("%s", niz);
	
	sestEj(niz);

	free(niz);
    return 0;
}

