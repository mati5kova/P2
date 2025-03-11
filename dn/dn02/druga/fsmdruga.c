#include <stdio.h>
#include <stdbool.h>

enum Stanje {
	S0 = 0,// izhod -> '0'
	S1 = 1,// izhod -> '1'
	S2 = 2,// izhod -> '1'
	S3 = 3,// izhod -> '0'
	S4 = 4,// izhod -> '1'
	S5 = 5,// izhod -> '0'
	S6 = 6,// izhod -> '1'
	S7 = 7, // naknadno dodano zaradi napake
	X = 8 // izhod -> '0'
};

void izpisiStanje(int stanje)
{
	switch(stanje)
	{
		case 0:case 3:case 5:case 8:
			putchar('0');
			break;
		case 1:case 2:case 4:case 6:case 7:
			putchar('1');
			break;
		default:
			break;
			
	}
}

int main()
{
	enum Stanje stanje = S0;
	char c;
	
	while((c = getchar()) != '\n' && c != EOF)
	{
		switch (stanje) 
		{
			case S0:
				switch(c)
				{
					case '1':case '2':case '3':case '4':case '5':
					case '6':case '7':case '8':case '9':
						stanje = S1;
						break;
					case '0':
						stanje = S2;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
				break;
				
			case S1:
				switch(c)
				{
					case '0':case '1':case '2':case '3':case '4':case '5':
					case '6':case '7':case '8':case '9':
						stanje = S1;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
				break;
				
			case S2:
				switch(c)
				{
					case '0':case '1':case '2':case '3':case '4':case '5':
					case '6':case '7':
						stanje = S7;
						break;
					case 'x':
						stanje = S3;
						break;
					case 'b':
						stanje = S5;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
				break;
				
			case S3:
				switch(c)
				{
					case '0':case '1':case '2':case '3':case '4':case '5':
					case '6':case '7':case '8':case '9':case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':
						stanje = S4;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;					
				}
				break;

			case S4:
				switch (c)
				{
					case '0':case '1':case '2':case '3':case '4':case '5':
					case '6':case '7':case '8':case '9':case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':
						stanje = S4;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
				break;
				
			case S5:
				switch (c)
				{
					case '0':case '1':
						stanje = S6;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
				break;
	
			case S6:
				switch(c)
				{
					case '0':case '1':
						stanje = S6;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
				break;
			case S7:
				switch(c)
				{
					case '0':case '1':case '2':case '3':case '4':case '5':
					case '6':case '7':
						stanje = S7;
						break;
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
				break;
			case X:
				switch(c)
				{
					case ' ':
						izpisiStanje(stanje);
						stanje = S0;
						break;
					default:
						stanje = X;
						break;
				}
			
			default:
				break;
				
		}
	}
	// treba ker ko je '\n' se ne izpiše in je
	// potrebno dodatno izpisati zadnje stanje
	izpisiStanje(stanje);
	putchar('\n');
	return 0;
}