#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void izpisi(int* t, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(i % 2 == 0)
			printf("%d", t[i]);
		else
			printf("[%d]", t[i]);
		if(i != len - 1)
			printf(" -> ");
	}
	printf("\n");
}

bool igraj(int preostaliZetoni, int k, bool beliNaPotezi, int* poteze, int steviloOdigranihPotez, bool izpisujZmage)
{
	if(preostaliZetoni == 0)
	{
		if(!beliNaPotezi && izpisujZmage)
		{
			izpisi(poteze, steviloOdigranihPotez);
		}
		
		// vrne true ce je beli zmagal (torej je trenutno crni na potezi)
		return !beliNaPotezi;
		
	} else if(preostaliZetoni < 0)
	{
		// nikoli ne pride do tega, samo za debugiranje
		printf("neveljavna poteza\n");//neveljavna poteza
	}
	
	// prvi klic iz maina samo isce ali obstaja taka resitev da bo beli zmagal (prav tako preverjanje v drugem delu (bool beliZmagal pred identicnim klicem ampak z izpisujZmage=true))
	// nekatere veje drevesa lahko skippamo ker ni pomembno da obiscemo vse, ce se prej izpolnejo dolecni pogoji
    if (!izpisujZmage) {
        if (beliNaPotezi) {
            for (int i = k; i >= 1; --i) {
                if (preostaliZetoni - i < 0) continue;
				
                poteze[steviloOdigranihPotez] = i;
				bool beliZmaga = igraj(preostaliZetoni - i, k, false, poteze, steviloOdigranihPotez + 1, false);
                
				if (beliZmaga) return true;
            }
            return false;
        }
        else {
            if (preostaliZetoni - k <= 0) return false;
			
            for (int i = 1; i <= k; ++i) {
                if (preostaliZetoni - i < 0) break;
				
                poteze[steviloOdigranihPotez] = i;
				bool beliZmaga = igraj(preostaliZetoni - i, k, false, poteze, steviloOdigranihPotez + 1, false);
                
				if (beliZmaga) return false;
            }
            return true;
        }
    }
    
	// drugi klic iz maina, ideja je da najprej pogledamo ce v tej veji beli zmaga, ce zmaga klicemo ponovno ampak z izpisujZmage=true
	// + ne skippamo vej ampak pregledamo vse
    if (beliNaPotezi) {
        for (int i = k; i >= 1; --i) {
            if (preostaliZetoni - i < 0) continue;
           
			poteze[steviloOdigranihPotez] = i;
			bool beliZmaga = igraj(preostaliZetoni - i, k, false, poteze, steviloOdigranihPotez + 1, false);
			
			if(beliZmaga)
			{
				igraj(preostaliZetoni - i, k, false, poteze, steviloOdigranihPotez + 1, true);
				break;
			}
        }
    }
    else {
        for (int i = 1; i <= k; ++i) {
            if (preostaliZetoni - i < 0) break;
			
            poteze[steviloOdigranihPotez] = i;
           	bool beliZmaga = igraj(preostaliZetoni - i, k, true, poteze, steviloOdigranihPotez + 1, false);
			
			if(beliZmaga)
			{
				igraj(preostaliZetoni - i, k, true, poteze, steviloOdigranihPotez + 1, true);
			}
        }
    }
    return true;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	bool beliZmagalCeloIgro = false;
	
	for (int i = k; i >= 1 && !beliZmagalCeloIgro; --i) {
		if(n - i < 0) continue; // ce npr k > n
		
		int* poteze = calloc(62, sizeof *poteze);
		poteze[0] = i;
		
		// ce dobimo nazaj feedback da s trenutnim i-jem beli zmaga v vseh scenarijih
		// igramo se enkrat ampak tokrat izpisujemo
		bool beliZmagaVse = igraj(n - i, k, false, poteze, 1, false);
		
		if (beliZmagaVse) {
			igraj(n - i, k, false, poteze, 1, true);
			beliZmagalCeloIgro = true;
		}
		free(poteze);
	}
	
	if (!beliZmagalCeloIgro) {
		printf("CRNI\n");
	}
	
	return 0;
}
