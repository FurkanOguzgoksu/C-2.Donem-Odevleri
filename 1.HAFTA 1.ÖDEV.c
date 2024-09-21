// 1- 0 ile 1000 arasında rasgele ürettiğinin 100 adet tam sayıyı sayilar.txt dosyasına yazınız.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *dosya;
	dosya = fopen("Sayilar.txt" , "w");
	
	if(dosya == NULL) {
		printf("Dosya acma hatasý!");
		return 1;
	}
	
	srand(time(NULL));
	
	for(int i=0 ; i<100 ; i++) {
		int sayi = rand()%1000;
		fprintf(dosya , "%d\n" , sayi);
	}
	fclose(dosya);
	printf("Sayilar 'Sayilar.txt' e yazildi...");
	return 0;
}

