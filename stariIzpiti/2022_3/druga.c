#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NIZ_LEN 1001

typedef struct _Vozlisce {
	char* niz;
	struct _Vozlisce* naslednje;
} Vozlisce;

void vstaviH1(Vozlisce* zacetek)
{
	Vozlisce* prejsnje = NULL;
	Vozlisce* temp = zacetek;
	
	while(temp != NULL)
	{
		
		if(strlen(temp->niz) != 0)
		{
			if(prejsnje == NULL || strlen(prejsnje->niz) == 0)
			{
				 if(temp->naslednje == NULL || strlen(temp->naslednje->niz) == 0)
				 {
					 // obogatimo niz
					 char* buffer = malloc(MAX_NIZ_LEN * sizeof(char));
					 strcpy(&(buffer[4]), temp->niz);
					 
					 char h1[] = "<h1>";
					 for(int i = 0; i < 4; i++)
					 	buffer[i] = h1[i];

					 
					 int len = strlen(buffer);
					 
					 char bh1[] = "</h1>";
					 for(int i = len; i < len + 5; i++)
						 buffer[i] = bh1[i - len];
					 
					 buffer[len + strlen(bh1)] = '\0';
					 
					 strcpy(temp->niz, buffer);
					 
					 free(buffer);
				 }
			}			
		}
		prejsnje = temp;
		temp = temp->naslednje;
	}
}

int main()
{
	/* testni primer iz izpita */
	char *texts[] = {
        "Dnevnik",
        "",
        "5. september 2022",
        "",
        "Danes opravljam izpit pri",
        "Programiranju 2.",
        "",
        "Ne smem pozabiti na koncno niclo!"
    };
    int n = sizeof(texts) / sizeof(texts[0]);
    
    Vozlisce *zacetek = NULL, *rep = NULL;
    for (int i = 0;  i < n;  i++) {
        Vozlisce *v = malloc(sizeof *v);
        v->niz = malloc(MAX_NIZ_LEN * sizeof(char));
        strcpy(v->niz, texts[i]);
        v->naslednje = NULL;
        if (rep) {
            rep->naslednje = v;
        } else {
            zacetek = v;
        }
        rep = v;
    }

    vstaviH1(zacetek);

    puts("After vstaviH1:");
    for (Vozlisce *p = zacetek;  p;  p = p->naslednje) {
        printf("[%s]\n", p->niz);
    }

    // cleanup
    while (zacetek) {
        Vozlisce *next = zacetek->naslednje;
        free(zacetek->niz);
        free(zacetek);
        zacetek = next;
    }

    return 0;
}

