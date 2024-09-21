#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int veri;
    struct dugum* sonraki;
};
struct dugum* stack_ekle(struct dugum* ust, int veri) {
    struct dugum* yeni = (struct dugum*)malloc(sizeof(struct dugum));
    yeni->veri = veri;
    yeni->sonraki = ust;
    return yeni;
}
struct dugum* queue_ekle(struct dugum* ilk, int veri) {
    struct dugum* yeni = (struct dugum*)malloc(sizeof(struct dugum));
    yeni->veri = veri;
    yeni->sonraki = NULL;
    if (ilk == NULL) {
        ilk = yeni;
    } else {
        struct dugum* gecici = ilk;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
    return ilk;
}
struct dugum* stack_cikar(struct dugum* ust) {
    if (ust == NULL) {
        printf("Stack bos, eleman cikarilamaz!");
        return ust;
    }
    struct dugum* gecici = ust;
    ust = ust->sonraki;
    free(gecici);
    return ust;
}
struct dugum* queue_cikar(struct dugum* ilk) {
    if (ilk == NULL) {
        printf("Queue bos, eleman cikarilamaz!");
        return ilk;
    }
    struct dugum* gecici = ilk;
    ilk = ilk->sonraki;
    free(gecici);
    return ilk;
}
void BulVeGoster(struct dugum* ust, int aranan) {
    struct dugum* gecici = ust;
    int sayac = 0;
    while (gecici != NULL) {
        if (gecici->veri == aranan) {
            printf("Aranan deger: %d, Adresi: %p\n", aranan, (void*)gecici);
            sayac++;
        }
        gecici = gecici->sonraki;
    }
    if (sayac == 0) {
        printf("Aranan deger bulunamadi!\n");
    }
}
void stack_listele(struct dugum* ust) {
    if (ust == NULL) {
        printf("Stack bos.\n");
        return;
    }
    printf("Stack elemanlari: ");
    while (ust != NULL) {
        printf("%d ", ust->veri);
        ust = ust->sonraki;
    }
}
void queue_listele(struct dugum* ilk) {
    if (ilk == NULL) {
        printf("Queue bos.\n");
        return;
    }
    printf("Queue elemanlari: ");
    while (ilk != NULL) {
        printf("%d ", ilk->veri);
        ilk = ilk->sonraki;
    }
}
int main() {
    struct dugum* stack_ust = NULL,* queue_ilk = NULL;
    int veri, aranan, secim, secim1;
    printf("Hangi yapinin kullanacagini seciniz:\n1-) Stack\n2-) Queue\n-->");
    scanf("%d", &secim);
    switch (secim) {
    case 1:
        printf("\n\n-1 yazarak cikis yapabilirsiniz...\n");
        while (1) {
            printf("Sayi giriniz:");
            scanf("%d", &veri);
            if (veri == -1) {
                break;
            }
            stack_ust = stack_ekle(stack_ust, veri);
        }
        printf("\n\nYapmak istediginiz islemi seciniz:\n1-) Ekle ve goster\n2-) Sil ve goster\n3-) Bul ve goster\n4-) Tumunu listele\n-->");
        scanf("%d", &secim1);
        switch (secim1) {
        case 1:
            printf("Eklenecek sayiyi giriniz:");		scanf("%d", &veri);
            stack_ust = stack_ekle(stack_ust, veri);
            stack_listele(stack_ust);
            break;
        case 2:
            stack_ust = stack_cikar(stack_ust);
            stack_listele(stack_ust);
            break;
        case 3:
            printf("Aranacak sayiyi giriniz:");		scanf("%d", &aranan);
            BulVeGoster(stack_ust, aranan);
            stack_listele(stack_ust);
            break;
        case 4:
            printf("Liste: ");
            stack_listele(stack_ust);
            break;
        default:
            printf("Gecersiz islem sectiniz!\n");
            break;
        }
    break;
    case 2:
        printf("\n-1 yazarak cikis yapabilirsiniz...\n");
        while (1) {
            printf("Sayi giriniz:");	scanf("%d", &veri);
            if (veri == -1) {
                break;
            }
            queue_ilk = queue_ekle(queue_ilk, veri);
        }
        printf("\n\nYapmak istediginiz islemi seciniz:\n1-) Ekle ve goster\n2-) Sil ve goster\n3-) Bul ve goster\n4-) Tumunu listele\n-->");
        scanf("%d", &secim1);
        switch (secim1) {
        case 1:
            printf("Eklenecek sayiyi giriniz:");	scanf("%d", &veri);
            queue_ilk = queue_ekle(queue_ilk, veri);
            queue_listele(queue_ilk);
            break;
        case 2:
            queue_ilk = queue_cikar(queue_ilk);
            queue_listele(queue_ilk);
            break;
        case 3:
            printf("Aranacak sayiyi giriniz:");		scanf("%d", &aranan);
            BulVeGoster(queue_ilk, aranan);
            queue_listele(queue_ilk);
            break;
        case 4:
            printf("Liste: ");
            queue_listele(queue_ilk);
            break;
        default:
            printf("Gecersiz islem sectiniz!\n");
            break;
        }
    break;
    default:
        printf("Gecersiz islem sectiniz!\n");
        break;
    }
    return 0;
}

