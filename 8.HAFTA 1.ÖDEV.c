#include <stdio.h>
#include <stdlib.h>
struct node {
    int sayi;
    struct node* sonraki;
    struct node* onceki;
};
int main() {
    struct node *ilk = NULL, *gecici = NULL;
	printf("-1 girerek cikabilirsiniz.\n");
    while (1){
        int sayi;
        printf("Sayi giriniz: ");
        scanf("%d", &sayi);
        if (sayi == -1)
            break;
        if (ilk == NULL) {
            ilk = (struct node*)malloc(sizeof(struct node));
            ilk->sayi = sayi;
            ilk->sonraki = NULL;
            ilk->onceki = NULL;
            gecici = ilk;
        }else {
            gecici->sonraki = (struct node*)malloc(sizeof(struct node));
            gecici->sonraki->onceki = gecici;
            gecici = gecici->sonraki;
            gecici->sayi = sayi;
            gecici->sonraki = NULL;
        }   
    }
    gecici = ilk;
    while (gecici != NULL) {
        printf("\nAdres:%p , Degeri:%d , Onceki adres:%p , Sonraki adres:%p\n", gecici, gecici->sayi, gecici->onceki, gecici->sonraki);
        gecici = gecici->sonraki;
    }
    return 0;
}

