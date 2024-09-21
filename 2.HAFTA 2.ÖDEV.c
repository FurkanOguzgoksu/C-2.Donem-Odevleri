#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    FILE *dosya0 = fopen("sayilar0.txt", "w");
    FILE *dosya1 = fopen("sayilar1.txt", "w");
    
	if (dosya0 == NULL || dosya1 == NULL) {
        printf("Dosya acma hatasi!\n");
        return 1;
    }
    for (int i = 0; i < 100; i++) { 
        int randomsayi = rand() % 101; 
        
		if ((randomsayi & (1 << 5)) == 0) { 
            randomsayi |= (1 << 4);
            fprintf(dosya0 , "%d\n", randomsayi);
        } else { 
            randomsayi &=~(1 << 3); 
            fprintf(dosya1 , "%d\n", randomsayi);
        }
    }
    fclose(dosya0);
    fclose(dosya1);
    printf("Sayilar dosyalara yazildi.\n"); 	
    return 0;
}


