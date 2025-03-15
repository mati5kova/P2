#include <stdio.h>

void nKratIzpisiZnak(char c, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%c", c);
	}
}

void odlociSeInIzpisiKodiranoAliNKratPonovljeno(char c, int n)
{
	if(c == '#')
	{
		printf("##%d#", n);
	} else if(n >= 5)
	{
		printf("#%c%d#", c, n);				
	} else
	{
		nKratIzpisiZnak(c, n);
	}
}

int beriDoHashaInVrniDesetiskoVrednost()
{
	char c;
	int n = 0;
	while((c = getchar()) != '#')
	{
		n = n * 10 + (c - '0');
	}
	
	return n;
}

int main()
{
	int ukaz;
	scanf("%d", &ukaz);
	getchar(); //skippamo presledek
	
	char c;
	char prejsnji = '\0';
	int counterIstihZnakov = 1;

	char znakZaDekodiranje;
	
	while((c = getchar()))
	{
		if(ukaz == 1)
		{
			if(c == '\n')
			{
				//izpisemo kar se imamo in koncamo
				odlociSeInIzpisiKodiranoAliNKratPonovljeno(prejsnji, counterIstihZnakov);
				break;
			} else if(prejsnji == '\0')
			{
				prejsnji = c;
				continue;
			}
			
			if(c == prejsnji)
			{
				counterIstihZnakov++;
				continue;
			} else
			{
				//najprej izpisemo prejsnje znake
				odlociSeInIzpisiKodiranoAliNKratPonovljeno(prejsnji, counterIstihZnakov);
				
				prejsnji = c;
				counterIstihZnakov = 1;
			}
		} else if(ukaz == 2)
		{
			if(c == '\n') { break; }
			
			if(c != '#')
			{ 
				printf("%c", c);
			} else if(c == '#')
			{
				//prvi # ki se je pojavil, dekodirajmo vsebino				
				znakZaDekodiranje = getchar();
				
				counterIstihZnakov = beriDoHashaInVrniDesetiskoVrednost();

				nKratIzpisiZnak(znakZaDekodiranje, counterIstihZnakov);
			}
		}
	}
	
	putchar('\n');
	return 0;
}
