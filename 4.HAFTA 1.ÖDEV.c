#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int dizi[100];
	int *p = dizi;
	srand(time(NULL));
	for(int i=0 ; i<20 ; i++){
		*(p+i) = rand()%101;
	}
	printf("Rastgele olusturulan dizi:\n");
	for(int i=0 ; i<20 ; i++){
		printf("%d ",*(p+i));
	}
	printf("\n\n");
	int temp,j,maxIndex;
	for(int i=0 ; i<20-1 ;i++){
		maxIndex = i;
		for(j=i+1 ; j<20 ; j++){
			if(*(p+j) > *(p+maxIndex)){
				maxIndex=j;
			}
		}
		temp = *(p+i);
		*(p+i) = *(p+maxIndex);
		*(p+maxIndex) = temp;
	}
	printf("Buyukten kucuge siralanmis dizi:\n");
	for(int i=0 ; i<20 ; i++){
		printf("%d ",*(p+i));
	}	
	return 0;
}




