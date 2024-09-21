#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Ebob (int sayi , int sayi2)
{
	if (sayi2 == 0) {
		return sayi;
	}
	else {
	    return Ebob(sayi2,sayi%sayi2);	
    }
}
int main(){
	int sayi,sayi2,sonuc;
	printf("Ebobu bulunacak birinci sayiyi giriniz--> ");		scanf("%d",&sayi);
	printf("Ebobu bulunacak ikinci sayiyi giriniz--> ");		scanf("%d",&sayi2);
	sonuc = Ebob(sayi,sayi2);
	printf("\nEbob(%d,%d)=> %d",sayi,sayi2,sonuc);
	
	getch();
	return 0;
}

