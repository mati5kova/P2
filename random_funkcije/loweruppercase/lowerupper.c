#include <stdio.h>
#define DOLZINA 5

char crke[DOLZINA];

char lower(char c)
{
    if(c >= 'A' && c <= 'Z')
	return c - 'A' + 'a';


    return c;
}

char upper(char c)
{

    if(c >= 'a' && c <= 'z')
	return c - 'a' + 'A';

    return c;
}

void beri() {
    char c;
    int counter;

    while((c = getchar()) != EOF && c && c != '\n' && counter <= DOLZINA)
    {

	crke[counter] = c;
	++counter;

    }
}

int main()
{
    //'z'-> 122
    //'a' -> 97
    ////'A' -> 65
    beri();
    printf("\n");
    

    int i, c;
    for(i = 0; i < DOLZINA; ++i)
    {
	c = crke[i];
	if(c < 'a' && c >= 'A')
	    printf("%c", lower(c));
	else if(c > 'Z' && c <= 'z')
	    printf("%c", upper(c));
	else
	    printf("%c", c);
    }

    printf("\n");





    return 0;
}

