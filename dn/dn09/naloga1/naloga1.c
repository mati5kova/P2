#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ZGORNJA_MEJA 1e6+1 // v navodilih pise da so elementi max tako veliki

/*
 * malo hecna resitev, najprej sm elemente vstavljal od najmanjsega do najvecjega ampak so test02 do test05 timeoutali
 * -> treba je it od najvecjega do najmanjsega elementa (na vhodu pise da so urejeni narascajoce)
 * -> na ta nacin hitreje naletimo na robni pogoj >> if (vsotePodmnozic[j] + el > ciljnaVsota) << in gremo lahko hitreje naprej
 *
 * -> tezava pa je nastala pri izpisovanju, vse int** podmnozice so padajoce urejene + podmnozice med sabo (njihovi najmanjsi elementi) niso bile enako urejene npr. 312 namesto 321
 * resitev:
 * -> najdemo podmnozico s trenutno najmanjsim elementom in tako naprej, vsako podmnozico izpisemo od konca proti zacetku
 */
void izpisi(int** t, int* dolzine, int k)
{
    int* zeObiskaniIndeksi = calloc(k, sizeof(int));
    bool jePrvaPodmnozica = true;

    printf("{");
    
    for(int visited = 0; visited < k; visited++)
    {
        int currMin = ZGORNJA_MEJA;
        int indeks = -1;
        // poiscemo neobiskano podmnozico z najmanjsim "zadnjim" elementom
        for(int z = 0; z < k; z++)
        {
            if(!zeObiskaniIndeksi[z] && dolzine[z] > 0)
            {
                int minEl = t[z][dolzine[z] - 1];
                if(minEl < currMin)
                {
                    currMin = minEl;
                    indeks = z;
                }
            }
        }
        zeObiskaniIndeksi[indeks] = 1;

        // vejica za vsakim prejsnjim blokom (samo prvic ni)
        if(!jePrvaPodmnozica)
			printf(", ");

        // izpis izbrane podmnožice; elementi so v padajocem vrstnem redu zato jih izpisujemo nazaj
        printf("{");
        for(int j = dolzine[indeks] - 1; j >= 0; j--)
        {
            printf("%d", t[indeks][j]);
            if(j != 0) 
                printf(", ");
        }
        printf("}");
		
		jePrvaPodmnozica = false;
    }
	
    printf("}\n");

    free(zeObiskaniIndeksi);
}

bool valid(int* vsotePodmnozic, int k, int ciljnaVsota)
{
	for(int i = 0; i < k; i++)
	{
		if(vsotePodmnozic[i] != ciljnaVsota)
			return false;
	}
	return true;
}

void razbij(int* M, int n, int k, int ciljnaVsota, int indeksM, int** podmnozice, int* dolzinePodmnozic, int* vsotePodmnozic)
{
	if(indeksM == -1)
	{
		if(valid(vsotePodmnozic, k, ciljnaVsota))
		{
			izpisi(podmnozice, dolzinePodmnozic, k);
			return;
		}
		return;
	}
	
	int el = M[indeksM];
	
	for(int j = 0; j < k; j++)
	{
		// preskoci prepolne
		if (vsotePodmnozic[j] == ciljnaVsota)
			continue;
		// preskoci tiste, ki bi presegle
		if (vsotePodmnozic[j] + el > ciljnaVsota)
			continue;
		
		podmnozice[j][dolzinePodmnozic[j]] = el;
		dolzinePodmnozic[j]++;
		vsotePodmnozic[j] += el;
		
		razbij(M, n, k, ciljnaVsota, indeksM - 1, podmnozice, dolzinePodmnozic, vsotePodmnozic);
		
		podmnozice[j][dolzinePodmnozic[j]] = 0; // pomembno da nastavimo na 0 kar koli smo dali notri
		vsotePodmnozic[j] -= el;
		dolzinePodmnozic[j]--;
									// moramo dati break;
		if (vsotePodmnozic[j] == 0) // ce smo dali v podmnozico en element in ga nato odstranili in je podmnozica prazna bo potem
			break;					// v naslednjem loopu zgodba ponovljena samo isti element se bo nahajal v naslednji podmnozici
	}
}

int main()
{
	int n, k, vsotaM = 0;
	scanf("%d %d\n", &n, &k);
	
	int* M = (int*) malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &M[i]);
		vsotaM += M[i];
	}
	
	int** podmnozice = (int**) malloc(k * sizeof(int*));
	for(int i = 0; i < k; i++)
	{
		podmnozice[i] = (int*) calloc(n, sizeof(int));
	}
	
	int* dolzinePodmnozic = (int*) calloc(k, sizeof(int));
	int* vsotePodmnozic = (int*) calloc(k, sizeof(int));

	razbij(M, n, k, vsotaM / k, n - 1, podmnozice, dolzinePodmnozic, vsotePodmnozic);
	
	free(M);
	for(int i = 0; i < k; i++)
	{
		free(podmnozice[i]);
	}
	free(podmnozice);
	free(dolzinePodmnozic);
	free(vsotePodmnozic);
	return 0;
}