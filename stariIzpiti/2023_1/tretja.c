#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
 * ZELO ZELO ZELO GRDA REŠITEV
 */

typedef struct _Vozlisce Vozlisce;
struct _Vozlisce {
	int vsebina; 	 // »vsebina« vozlišča
	Vozlisce* desno; // kazalec na desnega soseda ( NULL v zadnjem stolpcu)
	Vozlisce* dol;   // kazalec na spodnjega soseda ( NULL v zadnji vrstici)
};

Vozlisce* ustvariNovo(int vsebina, Vozlisce* desno, Vozlisce* dol)
{
	Vozlisce* novo = malloc(sizeof(Vozlisce));
	novo->vsebina = vsebina;
	novo->desno = desno;
	novo->dol = dol;
	
	return novo;
}

int pridobiVisino(Vozlisce* zacetek)
{
	if(zacetek == NULL)
		return 0;
	return 1 + pridobiVisino(zacetek->dol);
}

int pridobiSirino(Vozlisce* zacetek)
{
	if(zacetek == NULL)
		return 0;
	return 1 + pridobiSirino(zacetek->desno);
}

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina)
{
	Vozlisce* absolutnoLevoZgoraj = start;
	Vozlisce* temp = absolutnoLevoZgoraj;
	
	int content = vsebina;
	
	int w = pridobiSirino(start);
	int h = pridobiVisino(start);
	
	Vozlisce* prejsnjeLevoZgoraj = start;
	if(mesto == 0)
	{
		
		for(int vrstica = 0; vrstica < h; vrstica++)
		{
			Vozlisce* novoLevoZgoraj = ustvariNovo(vsebina, prejsnjeLevoZgoraj, NULL);
			if(vrstica == 0)
			{
				absolutnoLevoZgoraj = novoLevoZgoraj;
			}
			vsebina += 1;
			if(vrstica != 0)
			{
				temp->dol = novoLevoZgoraj;				
			}
			temp = novoLevoZgoraj;
			prejsnjeLevoZgoraj = prejsnjeLevoZgoraj->dol;
		}
		
		return absolutnoLevoZgoraj;
	}
	
	if(h == 1)
	{
		for(int i = 0; i < mesto - 1; i++)
		{
			temp = temp->desno;
		}
		
		Vozlisce* novo = ustvariNovo(vsebina, temp->desno, NULL);
		temp->desno = novo;
		return absolutnoLevoZgoraj;
	} else
	{
		Vozlisce* temp2 = absolutnoLevoZgoraj;
		for(int vrstica = 0; vrstica < h; vrstica++)
		{
			temp = temp2;			
			for(int stolpec = 0; stolpec < mesto - 1; stolpec++)
			{
				temp = temp->desno;
			}
			Vozlisce* novo = ustvariNovo(vsebina, temp->desno, NULL);
			temp->desno = novo;
			vsebina += 1;
			
			temp2 = temp2->dol;
		}
		
		return absolutnoLevoZgoraj;
	}
	
}

void izpisi(Vozlisce* start)
{
	int w = pridobiSirino(start);
	int h = pridobiVisino(start);
	Vozlisce* levoZgoraj = start;
	
	for(int vrstica = 0; vrstica < h; vrstica++)
	{
		Vozlisce* temp = levoZgoraj;
		for(int stolpec = 0; stolpec < w; stolpec++)
		{
			printf("%d", temp->vsebina);
			
			if(stolpec != w - 1)
				printf(" -> ");
			
			temp = temp->desno;
		}
		printf("\n");
		
		levoZgoraj = levoZgoraj->dol;
	}
	printf("\n");
}

int main()
{
	Vozlisce* _12 = ustvariNovo(12, NULL, NULL);
	Vozlisce* _11 = ustvariNovo(11, _12, NULL);
	Vozlisce* _10 = ustvariNovo(10, _11, NULL);
	Vozlisce* _9 = ustvariNovo(9, _10, NULL);
	
	Vozlisce* _8 = ustvariNovo(8, NULL, _12);
	Vozlisce* _7 = ustvariNovo(7, _8, _11);
	Vozlisce* _6 = ustvariNovo(6, _7, _10);
	Vozlisce* _5 = ustvariNovo(5, _6, _9);
	
	Vozlisce* _4 = ustvariNovo(4, NULL, _8);
	Vozlisce* _3 = ustvariNovo(3, _4, _7);
	Vozlisce* _2 = ustvariNovo(2, _3, _6);
	Vozlisce* start = ustvariNovo(1, _2, _5);
	
	izpisi(start);
	
	Vozlisce* novStart = vstaviStolpec(start, 2, 100);
	
	izpisi(novStart);
	
	novStart = vstaviStolpec(novStart, 5, 200);
	
	izpisi(novStart);
	
	novStart = vstaviStolpec(novStart, 0, 300);
	
	izpisi(novStart);
	
	
	
    return 0;
}

