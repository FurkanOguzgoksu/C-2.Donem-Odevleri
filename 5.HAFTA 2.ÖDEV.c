#include <stdio.h>
#include <stdlib.h>

int main(){
	int sayi,sayac=0,i=0;
	int dizi[sayac],*p; 
	do{
		printf("Sayi giriniz:");
		scanf("%d",&sayi);	
	 	if(sayi%15 == 0 && sayi!=0){
	 		dizi[i] = sayi;
	 		i++;
			sayac++;
	 	 }
	}while(sayi>0);
	p=(int*)malloc(sayac*sizeof(int));
	if(p == NULL){
		printf("Bellek tahsis hatasi!");
	}
	if(sayac!=0){
		printf("\n\nDizinin icerisinde 3 ve 5'e tam bolunen sayilar:\n");	
		for(i=0 ; i<sayac ; i++){
	 		*(p+i)=dizi[i];
	 		printf("|%d| ",*(p+i));
		}
	}else{
		printf("\nDizinin icerisinde 3 ve 5'e tam bolunen sayi yoktur.");
	}
	free(p);
	return 0;
}


