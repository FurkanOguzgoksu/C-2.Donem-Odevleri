#include <stdio.h>
#include <stdlib.h>
struct OGRENCI {
    int id;
    float vize;
    float final;
    float ortalama;
    struct OGRENCI* sonraki;
};
int main() {
    struct OGRENCI *ilk = NULL;
    struct OGRENCI *ptr = NULL;
    struct OGRENCI *gecici = NULL;
    int id, kontrol = 1;
    float vize, final, ort = 0;

    printf("Cikmak icin ID'yi negatif giriniz.\n\n");
	while (kontrol == 1) {
        if (ilk == NULL) {
            ilk = (struct OGRENCI*)malloc(1*sizeof(struct OGRENCI));
            printf("Ogrenci ID'sini giriniz: ");
            scanf("%d", &id);
            if (id < 0) {
                kontrol = 0;
                break;
            }
            printf("Vize notunu giriniz: ");	scanf("%f",&vize);
            printf("Final notunu giriniz: ");	scanf("%f",&final);
			ort = vize * 0.4 + final * 0.6;
            ilk->vize = vize;
            ilk->final = final;
            ilk->ortalama = ort;
            ilk->id = id;
            ilk->sonraki = NULL;
            ptr = ilk;
        }else {
            ptr->sonraki = (struct OGRENCI*)malloc(1*sizeof(struct OGRENCI));
            ptr = ptr->sonraki;
            printf("Ogrenci ID'sini giriniz: ");
            scanf("%d",&id);
            if (id < 0) {
                kontrol = 0;
                break;
            }
            printf("Vize notunu giriniz: ");	scanf("%f",&vize);
            printf("Final notunu giriniz: ");	scanf("%f",&final);
            ort = vize * 0.4 + final * 0.6;
            ptr->vize = vize;
            ptr->final = final;
            ptr->id = id;
            ptr->ortalama = ort;
            ptr->sonraki = NULL;
        }   printf("\n");
    }		printf("\n\n");
    		printf("-------------------------------\n\nOgrenci Not Listesi:\n");
    gecici = ilk;
    while (gecici->sonraki!= NULL) {
    	printf("%d ID'li ogrencinin Vize notu: %.2f , Final notu: %.2f , Ortalamasi: %.2f\n",gecici->id, gecici->vize, gecici->final, gecici->ortalama);
   	    gecici = gecici->sonraki;
    }
    return 0;
}

