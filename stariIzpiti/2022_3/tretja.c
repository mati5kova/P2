#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
	int podatek;
	struct _Vozlisce* levo;
	struct _Vozlisce* desno;
} Vozlisce;

/* za potrebe izpisa in cleanupa*/
void izpis(Vozlisce* node, int* pot, int globina) {
    if (node == NULL) return;

    pot[globina++] = node->podatek;

    if (!node->levo && !node->desno) {
        for (int i = 0; i < globina; i++) {
            printf("%d", pot[i]);
            if (i+1 < globina) printf("->");
        }
        printf(";\n");
        return;
    }

    if (node->levo)  izpis(node->levo,  pot, globina);
    if (node->desno) izpis(node->desno, pot, globina);
}

void cleanup(Vozlisce* root) {
    if (!root) return;
    cleanup(root->levo);
    cleanup(root->desno);
    free(root);
}
/******************************/


/* zacetek naloge */
Vozlisce* ustvari(int podatek)
{
	Vozlisce* novo = malloc(sizeof(Vozlisce));
	novo->podatek = podatek;
	novo->levo = NULL;
	novo->desno = NULL;
	return novo;
}

Vozlisce* rek(int n, int* podatki, int* indeks, int globina)
{
	if(globina == n)
		return NULL;
	
	Vozlisce* node = ustvari(podatki[*indeks]);
	(*indeks)++;
	node->levo = rek(n, podatki, indeks, globina + 1);
	node->desno = rek(n, podatki, indeks, globina + 1);
		
	return node;
}

Vozlisce* drevo(int n, int* podatki)
{
	int indeks = 0;
	Vozlisce* koren = rek(n, podatki, &indeks, 0);
	
	return koren;
}

int main()
{
	/* testni primer iz izpita */
	int n = 4;
    int podatki_count = (1 << n) - 1;
    int* podatki = malloc(((1 << 4) - 1) * sizeof(int));
    for (int i = 0; i < podatki_count; i++) {
        podatki[i] = i;
    }

    Vozlisce* koren = drevo(n, podatki);
    if (!koren) {
        fprintf(stderr, "drevo returned NULL!\n");
        return 1;
    }

    printf("Level-order print of the tree (%d levels):\n", n);
	int* pot = malloc(podatki_count * sizeof(int));
    izpis(koren, pot, 0);

    // clean up
    cleanup(koren);
	free(podatki);
	free(pot);

    return 0;
}

