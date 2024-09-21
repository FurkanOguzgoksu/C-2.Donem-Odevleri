/* Kendisine parametre olarak gelen metni yine kendisine parametre olark gelen deðer kadar 
karakter temelli right rotated shift yapan fonksiyon kodunu pointer aritmetiði kullanarak yazýnýz */
#include <stdio.h>
#include <stdlib.h>

void right_rotated_shift(char metin[],int adet)
{
	char gecici[1];
	char *p = metin;
	char *g = gecici;
	int i,j,sayac=0;
	for(sayac=0 ; *(p+sayac)!='\0' ; sayac++);
	for(i=0 ; i<adet ;i++)		// Kaydirilma miktari kadar döngü devam eder.
	{
		*(g+0) = *(p+sayac-1);	// Metinin son indexini gecicide tutar.
		
		for(j=sayac-2 ; j>=0 ; j--)
		{
			*(p+j+1) = *(p+j);	// Her terim bir kez saga kayar.
		}
			*(p+0) = *(g+0);	// Gecicide tutulan son index en basa getirilir.
	}
	printf("%d defa kaydirilmis metinin yeni hali: %s",adet,p);
}
int main(){
	char metin[100];
	int adet;
	printf("Metin giriniz: ");
	gets(metin);
	printf("Metini kaydirma miktarini giriniz: ");
	scanf("%d",&adet);
	printf("\n");
	printf("Metinin ilk hali: %s \n",metin);
	right_rotated_shift(metin,adet);
	return 0;
}


