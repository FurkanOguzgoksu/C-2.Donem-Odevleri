#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
	int sayi;
	struct Node *sonraki;
};

struct Node* TersCevir(struct Node *suanki , struct Node *onceki){

	if(suanki==NULL){
		return onceki;
	}
	
	struct Node *sonraki = suanki->sonraki;
	suanki->sonraki = onceki;
	
	return TersCevir(sonraki,suanki);
}

int main(){
	srand(time(NULL));
	int elemanSayisi = rand() % 10 + 1;
	
	struct Node *ilk=NULL;
	struct Node *gecici=NULL;
	
	for(int i=0 ; i<elemanSayisi ; i++){
		struct Node *deger = (struct Node*)malloc(sizeof(struct Node));
		deger->sayi = rand() % 101;
		deger->sonraki=NULL;
		
		if(ilk==NULL){
			ilk=deger;
			gecici=ilk;
		}
		else{
			gecici->sonraki=deger;
			gecici=gecici->sonraki;
		}
	}
	printf("\nBaslangictaki Liste:\n");
	gecici=ilk;
	while(gecici!=NULL){
		printf("\nAdresi:%p , Degeri:%d , Sonraki Adresi:%p\n",gecici,gecici->sayi,gecici->sonraki);
		gecici = gecici->sonraki;
	}
	
	ilk=TersCevir(ilk,NULL);
	
	printf("\nTersine Cevrilmis Liste:\n");
	gecici=ilk;
	while(gecici!=NULL){
		printf("\nAdresi:%p , Degeri:%d , Sonraki Adresi:%p\n",gecici,gecici->sayi,gecici->sonraki);
		gecici = gecici->sonraki;
	}
	return 0;
}
