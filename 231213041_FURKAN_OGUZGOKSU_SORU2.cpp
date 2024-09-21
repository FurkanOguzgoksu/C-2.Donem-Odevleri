#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int sayi_top (int sayi)
{
	if (sayi<=0)
	{
		return 0;
    }
	else {
		return sayi + sayi_top(sayi-1);	
	}
}
int main(){
	int sayi,sonuc;
	printf("Hangi sayiya kadar olan sayilarin toplami hesaplanacak?\n--> ");
	scanf("%d",&sayi);
	sonuc = sayi_top(sayi);
	printf("\n%d ye kadar olan sayilarin toplami: %d",sayi,sonuc);
	
	getch();
	return 0;
}


