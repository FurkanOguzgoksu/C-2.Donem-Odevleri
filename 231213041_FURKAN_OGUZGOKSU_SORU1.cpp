#include <stdio.h>
#include <stdlib.h>
struct Node{
    int sayi;
    struct Node* sonraki;
};
int main() { 
    struct Node *ilk=NULL;
    struct Node *ptr=NULL;
    struct Node *gecici=NULL;
    int sayi,kontrol=1;
    printf("-1 girerek cikabilirsiniz.\n");
    while(kontrol==1){
        printf("sayi giriniz:");
        scanf("%d",&sayi);
        if(sayi==-1){
            kontrol=0;
            break;
        }
        if(ilk==NULL){
            ilk=(struct Node*)malloc(1*sizeof(struct Node));
            ilk->sayi=sayi; 
            ilk->sonraki=NULL; 
            ptr = ilk;
        }else{ 
            ptr->sonraki=(struct Node*)malloc(1*sizeof(struct Node));
            ptr=ptr->sonraki;
            ptr->sayi=sayi;
            ptr->sonraki=NULL; 
        }   
    }
    printf("\n");
    gecici=ilk;
    while(gecici!=NULL){
        printf("Adres:%p , Degeri:%d , Sonraki adres:%p\n",gecici,gecici->sayi,gecici->sonraki);
        gecici=gecici->sonraki;
    }
    return 0;
}

