#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// testni podatki za primer iz izpita
unsigned char _01a[] = {0xCB, 0x0A, 0x62, 0x9D, 0xF3};
unsigned char _01b[] = {0x4B, 0x90, 0x41, 0x9D, 0xC8, 0x81, 0x53};

unsigned char max(unsigned char a, unsigned char b) { return a > b ? a : b; }

int main(int argc, char* argv[])
{
    /* zacetek pisanja za testni primer */
    FILE* test_write = fopen(argv[1], "wb");
    if(!test_write)
    {
        printf("Napaka pri odpranju\n");
        exit(1);
    }
    fwrite(_01a, 1, sizeof(_01a), test_write);
    freopen(argv[2], "wb", test_write);
    fwrite(_01b, 1, sizeof(_01b), test_write);
    fclose(test_write);
    /* konec pisanja za testni primer */
    
    
    FILE* f1 = fopen(argv[1], "rb");
    if(!f1)
    {
        printf("Napaka pri branju\n");
        exit(1);
    }
    FILE* f2 = fopen(argv[2], "rb");
    if(!f2)
    {
        printf("Napaka pri branju\n");
        fclose(f1);
        exit(1);
    }
    FILE* out = fopen(argv[3], "wb");
    if(!out)
    {
        printf("Napaka pri odpiranju\n");
        fclose(f1);
        fclose(f2);
        exit(1);
    }
    
    while(1)
    {
        unsigned char bajt1 = 0, bajt2 = 0;
        int st1 = fread(&bajt1, 1, 1, f1);
        int st2 = fread(&bajt2, 1, 1, f2);
        
        if(st1 != 0 || st2 != 0)
        {
            unsigned char rez = max(bajt1, bajt2);
            fwrite(&rez, 1, 1, out);
        } else 
        {
            break;
        }
    }
    
    
    fclose(f1);
    fclose(f2);
    fclose(out);
    
    return 0;
}

