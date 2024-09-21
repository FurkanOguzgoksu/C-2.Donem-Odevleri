#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int LRS (int sayi , int kaydir)
{
	unsigned short sonuc,sonuc2; 	
	
	sonuc = sayi << kaydir ;  
	sonuc2 = sayi >> (16-kaydir);	// Veri kaybını önlemek için yapılmıştır.
	
	return (sonuc|sonuc2); 
}
int main(){
	unsigned short sonuc;
	int sayi,kaydir;
	
	printf("Sola kaydirilack sayiyi giriniz:");	  scanf("%d",&sayi);
	printf("Kaydirilacak miktari giriniz:");	  scanf("%d",&kaydir);
	
	sonuc = LRS(sayi,kaydir);
	printf("\n%d sayisinin %d defa sola kaydirilmasiyla olusan yeni sayi: %d",sayi,kaydir,sonuc);	
	
	getch();
	return 0;
}

