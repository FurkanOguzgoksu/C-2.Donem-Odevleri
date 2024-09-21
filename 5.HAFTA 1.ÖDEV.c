#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int dizi[100],i,sayi,*p,sayac=0;
	FILE *dosya = fopen("sayi.txt","w");
	if(dosya==NULL){
		printf("Dosya acma hatasi!");
		return 0;
	}
	for(i=0 ; i<100 ; i++){
		sayi = rand()%101;
		fprintf(dosya,"%d\n",sayi);
		if((sayi & (1 << 4))==0){
			dizi[sayac]=sayi;
			sayac++;
		}
	}
	p = (int*)malloc(sayac*sizeof(int));
	if (p == NULL) {
        printf("Bellek tahsis hatasi!");
        return 0;
    }
    printf("Sayi.txt dosyasindaki 5.biti 0 olan sayilar:\n");
	for(i=0;i<sayac;i++){	
		*(p+i)=dizi[i];
	  	printf("|%d| ",*(p+i));
	}
	fclose(dosya);
	free(p);
	return 0;
}


