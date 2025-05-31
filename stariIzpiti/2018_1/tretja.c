#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int absRazlika(int a, int b)
{
	int rez = a - b;
	
	return rez < 0 ? 0 - rez : rez;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int sestejElementePodmnozice(int* podmn, int st)
{
	int suma = 0;
	for(int i = 0; i < st; i++)
	{
		suma += podmn[i];
	}
	
	return suma;
}

int rek(int* t, int n, int item, int* t1, int* t2, int steviloT1, int steviloT2)
{
	if(item >= n)
	{
		return absRazlika(sestejElementePodmnozice(t1, steviloT1), sestejElementePodmnozice(t2, steviloT2));
	}
	
	// polozimo t[item] v prvo podmnozico
	t1[steviloT1] = t[item];
	int prvaOpcija = rek(t, n, item + 1, t1, t2, steviloT1 + 1, steviloT2);


	// polozimo t[item] v drugo podmnozico
	t2[steviloT2] = t[item];
	int drugaOpcija = rek(t, n, item + 1, t1, t2, steviloT1, steviloT2 + 1);
	
	return min(prvaOpcija, drugaOpcija);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int* t = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &(t[i]));
	}
	
	int t1[20];
	int t2[20];
	
	int rez = rek(t, n, 0, t1, t2, 0, 0);
	printf("%d\n", rez);
	
	free(t);
	return 0;
}