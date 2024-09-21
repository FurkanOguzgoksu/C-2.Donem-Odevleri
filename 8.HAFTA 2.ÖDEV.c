#include <stdio.h>
#include <stdlib.h>

struct Node{
	int sayi;
	struct Node *sonraki;
	struct Node *onceki;
};

int main(){
	struct Node *ilk=NULL , *gecici=NULL , *yeni=NULL , *onceki=NULL;
	
	printf("Cikmak icin -1 e basiniz...\n");
	while(1){
		yeni = (struct Node*)malloc(sizeof(struct Node));
		
		printf("Eklenecek sayiyi giriniz:");
		scanf("%d",&yeni->sayi);
		
		if(yeni->sayi==-1){
			free(yeni);
			break;
		}
		
		yeni->sonraki=NULL;
		
		if(ilk==NULL){
			ilk=yeni;	
		}
		
		else if(ilk->sayi > yeni->sayi){
			yeni->sonraki = ilk;
			ilk->onceki = yeni;
			ilk=yeni;
		}
		
		else{
			onceki = ilk;
			gecici = ilk->sonraki;
			ilk->onceki = gecici;
			
			while(gecici!=NULL){
				
				if(gecici->sayi < yeni->sayi) {
                    onceki = onceki->sonraki;
                    gecici = gecici->sonraki;
                } 
				else {
                    break;
				}
			}
			
			if(gecici == NULL) {
                onceki->sonraki = yeni;
                yeni->onceki = onceki;
            } 
			
			else {
                onceki->sonraki = yeni;
                yeni->onceki = onceki;
                yeni->sonraki = gecici;
                gecici->onceki = yeni;
            }
		}
	}
	
	gecici = ilk;
    gecici->onceki=NULL;
	
	while(gecici != NULL) {
        printf("\nAdres:%p , Degeri:%d , Onceki adres:%p , Sonraki adres:%p\n", gecici, gecici->sayi, gecici->onceki, gecici->sonraki);
        gecici = gecici->sonraki;
    }
    
    // Belleği serbest bırakma
    gecici = ilk;
    while (gecici != NULL) {
        struct Node *tmp = gecici;
        gecici = gecici->sonraki;
        free(tmp);
    }
    
    return 0;
}
