#include <stdio.h>
#include <stdlib.h>

int asalMi(int sayi)
{
    if (sayi <= 1)
    {
        return 0; 
    }
    for (int i = 2; i < sayi; i++)
    {
        if (sayi % i == 0)
        {
            return 0; 
        }
    }
    return 1; 
}

int main()
{
    FILE *giris_dosya, *cikis_dosya;
    int sayi;

    giris_dosya = fopen("Sayilar.txt" , "r");
    if (giris_dosya == NULL)
    {
        printf("Dosya acma hatasi!");
        return 1;
    }

    cikis_dosya = fopen("Sayilar2.txt" , "w"); 
    if (cikis_dosya == NULL)
    {
        printf("Dosya acma hatasi!");
        return 1;
    }

    while (fscanf(giris_dosya, "%d", &sayi) != EOF)
    {
        if (asalMi(sayi) == 1)
        {
            fprintf(cikis_dosya, "%d\n", sayi);
        }
    }
    fclose(giris_dosya);
    fclose(cikis_dosya);
    printf("\n'Sayilar.txt' teki asal sayilar 'Sayilar2.txt' e kaydedildi...\n");
    return 0;
}

