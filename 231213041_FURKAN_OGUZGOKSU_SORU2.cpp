#include <stdio.h>
#include <stdlib.h>
struct Node {
    int sayi;
    struct Node* sonraki;
};
int main() {
    struct Node *ilk = NULL;
    struct Node *ptr = NULL;
    struct Node *gecici = NULL;
    int sayi, aranan, kontrol = 1;

    printf("-1 girerek cikabilirsiniz.\n");
    while (kontrol == 1) {
        printf("Sayi giriniz:");
        scanf("%d", &sayi);
        if (sayi == -1) {
            kontrol = 0;
            break;
        }
        if (ilk == NULL) {
            ilk = (struct Node*)malloc(1*sizeof(struct Node));
            ilk->sayi = sayi;
            ilk->sonraki = NULL;
            ptr = ilk;
        } else {
            ptr->sonraki = (struct Node*)malloc(1*sizeof(struct Node));
            ptr = ptr->sonraki;
            ptr->sayi = sayi;
            ptr->sonraki = NULL;
        }
    }
    printf("\n");
    gecici = ilk;
    while (gecici != NULL) {
        printf("Adres:%p , Degeri:%d , Sonraki adres:%p\n", gecici, gecici->sayi, gecici->sonraki);
        gecici = gecici->sonraki;
    }
    printf("\n");
    printf("Aranan sayiyi giriniz:");
    scanf("%d", &aranan);

    struct Node *arama = NULL;
    gecici = ilk;
    kontrol = 0;
    while (gecici != NULL) {
        if (gecici->sayi == aranan) {
            kontrol = 1;
            arama = gecici;
            break;
        }
        gecici = gecici->sonraki;
    }
    if (kontrol != 0) {
        printf("\nAranan %d sayisi bulundu.\n", arama->sayi);
        
        if (arama == ilk) {
            ilk = ilk->sonraki;
            free(arama);
        }else {
            gecici = ilk;
            while (gecici->sonraki != arama){
            	gecici = gecici->sonraki;
			}
            gecici->sonraki = gecici->sonraki->sonraki;
            free(arama);
        }
    }else {
        printf("Aranan sayi bulunamadý.");
    }
	gecici = ilk;
    printf("\nYeni liste:\n");
    while (gecici != NULL) {
        printf("Adres:%p  , Degeri:%d  , Sonraki adres:%p\n", gecici, gecici->sayi, gecici->sonraki);
        gecici = gecici->sonraki;
    }
    return 0;
}

