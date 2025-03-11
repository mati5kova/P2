#include <stdio.h>
#include <stdbool.h>

char beriDoKoncaNiza()
{
	char c;
	while((c = getchar()) != ' ' && c != '\n' && c != EOF)
	{
		continue;
	}
	return c;
}

int dolociVrsto(char znak)
{
	int vrsta = 0;
	
	if(znak >= '1' && znak <= '9')
	{
		vrsta = 1;
	} else if(znak == '0')
	{
		vrsta = 2;
	} else
	{
		vrsta = -1;
	}

	return vrsta;
}

int main()
{
	bool konec = false;
	
	while(!konec)
	{
		// 1: [1-9][0-9]
		// 2: [0]...
		// 21:[0][0-7]
		// 22: [0x][0-F]
		short int vrsta = 0;
		char znak, c;
		bool prviZnak = true;
		
		while(1)
		{
			znak = getchar();
			
			if(prviZnak)
			{
				prviZnak = false;
				vrsta = dolociVrsto(znak);
			} else
			{
				if(vrsta == -1)
				{
					c = beriDoKoncaNiza();
					if(c == '\n')
					{
						konec = true;
						putchar('0');
						break;
					}	
					putchar('0');
					break;
				} else if(vrsta == 1)
				{
					if(znak == ' ')
					{
						putchar('1');
						break;
					} else if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					} else if(znak < '0' || znak > '9')
					{
						putchar('0');
						c = beriDoKoncaNiza();
						if(c == '\n')
							konec = true;
						
						break;
					}
				} else if(vrsta == 2)
				{
					if(znak == ' ')
					{
						putchar('1');
						break;
					} else if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					} else if(znak == 'x')
					{
						vrsta = 22;
						znak = getchar();
						if(znak == ' ')
						{
							putchar('0');
							break;
						}
					}else if(znak == 'b')
					{
						vrsta = 23;
						znak = getchar();
						if(znak == ' ')
						{
							putchar('0');
							break;
						}
					} else if(znak >= '0' && znak <= '7')
					{
						vrsta = 21;
					} else
					{
						putchar('0');
						c = beriDoKoncaNiza();
						if(c == '\n')
							konec = true;
						
						break;
					}
				} else if(vrsta == 21)
				{
					if(znak == ' ')
					{
						putchar('1');
						break;
					} else if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					} else if(znak < '0' || znak > '7')
					{
						putchar('0');
						c = beriDoKoncaNiza();
						if(c == '\n')
							konec = true;
						
						break;
					}
				} else if(vrsta == 22)
				{
					if(znak == ' ')
					{
						putchar('1');
						break;
					} else if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					} else if((znak >= '0' && znak <= '9') || (znak >= 'A' && znak <= 'F'))
					{
						
						continue;
					} else 
					{
						putchar('0');
						c = beriDoKoncaNiza();
						if(c == '\n')
							konec = true;
						
						break;
					}
				}else if(vrsta == 23)
				{
					if(znak == ' ')
					{
						putchar('1');
						break;
					} else if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					} else if(znak < '0' || znak > '1')
					{
						putchar('0');
						c = beriDoKoncaNiza();
						if(c == '\n')
							konec = true;
						
						break;
					}
				}
			}
		}
	}
	
	putchar('\n');
	return 0;
}