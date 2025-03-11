#include <stdio.h>
#include <stdbool.h>

/*
	PREDEN SEM PREBRAL NAMIG IN NAREDIL Z FSM
	ZA FSM IMPLEMENTACIJO GLEJ DRUGO NALOGO fsmdruga.c
*/

char beriDoNovegaNiza()
{
	char c;
	while((c = getchar()) != ' ' && c != '\n' && c != EOF)
	{
		continue;
	}
	return c;//za '\n' check
}

int dolociVrsto(char znak)
{
	short int vrsta = 0;
	if(znak == '0')
	{
		vrsta = 1;
	} else if(znak >= '1' && znak <= '9')
	{
		vrsta = 2;
	} else if(znak == '+' || znak == '-')
	{
		vrsta = 3;
	} else
		vrsta = -1;
	return vrsta;
}

int main()
{
	bool konec = false;
	
	while(!konec)
	{
		bool jePrviZnak = true;
		// 1: niz ki ga sestavlja samo 0
		// 2: zacetek:1-9 in nadaljuje z 0-9
		// 3: +-
		// 31: +-0_
		// 32: +-[1-9][0-9]
		short int vrsta = 0;
		char znak, c;
		
		while(1)
		{
			znak = getchar();
			
			if(jePrviZnak)
			{
				jePrviZnak = false;
				vrsta = dolociVrsto(znak);
				continue;
			} else 
			{
				if(vrsta == 1)
				{
					if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					}
					if(znak == ' ')
					{
						//printf("[0_: 1]");
						putchar('1');
						break;
					} else 
					{
						c = beriDoNovegaNiza();
						if(c == '\n')
						{
							konec = true;
							putchar('0');
							break;
						}	
						//printf("[0xyz: 0]");
						putchar('0');
						break;
					}
				} else if(vrsta == 2)
				{
					if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					}
					if(znak == ' ')
					{
						//printf("[[1-9][0-9]: 1]");
						putchar('1');
						break;
					} else if(znak >= '0' && znak <= '9')
					{
						continue;
					} else
					{
						c = beriDoNovegaNiza();
						if(c == '\n')
						{
							konec = true;
							putchar('0');
							break;
						}	
						//printf("[[1-9][0-9]xyz: 0]");
						putchar('0');
						break;
					}
				} else if(vrsta == 3)
				{
					if(znak == '\n')
					{
						putchar('0');
						konec = true;
						break;
					}
					if(znak == ' ')
					{
						//printf("[+-_: 0]");
						putchar('0');
						break;
					} else if(znak == '0')
					{
						vrsta = 31;
					} else if(znak >= '1' && znak <='9')
					{
						vrsta = 32;
					} else
					{
						c = beriDoNovegaNiza();
						if(c == '\n')
						{
							konec = true;
							putchar('0');
							break;
						}	
						//printf("[+-xyz: 0]");
						putchar('0');
						break;
					}
				} else if(vrsta == 31)
				{
					if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					}
					if(znak == ' ')
					{
						//printf("[+-0_: 1]");
						putchar('1');
						break;
					} else
					{
						c = beriDoNovegaNiza();
						if(c == '\n')
						{
							konec = true;
							putchar('0');
							break;
						}
						//printf("[+-0xyz: 0]");
						putchar('0');
						break;
					}
				} else if(vrsta == 32)
				{
					if(znak == '\n')
					{
						putchar('1');
						konec = true;
						break;
					}
					if(znak == ' ')
					{
						//printf("[+-[1-9][0-9]: 1]");
						putchar('1');
						break;
					} else if(znak >= '0' && znak <='9')
					{
						continue;
					} else
					{
						c = beriDoNovegaNiza();
						if(c == '\n')
						{
							konec = true;
							putchar('0');
							break;
						}	
						//printf("[+-[1-9][0-9]xyz: 0]");
						putchar('0');
						break;
					}
				} else if(vrsta == -1)
				{
					//invalid chararcter na prvem mestu
					
					c = beriDoNovegaNiza();
					if(c == '\n')
					{
						konec = true;
						putchar('0');
						break;
					}	
					//printf("[+-[1-9][0-9]xyz: 0]");
					putchar('0');
					break;
				}
			}
		}
	}
	
	putchar('\n');
	return 0;
}