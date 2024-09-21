#include <stdio.h>
#include <conio.h>
#include <string.h>
int palindrommu(char *str, int len)
{
 if(len<2) return 1;
 return ( str[0] == str[len-1] ) && palindrommu( &str[1] , len-2 );
}
int main() {
 char kr,mtn[100];
 int sonuc;
 do {
 printf("Metin giriniz...:");
 gets(mtn);
 sonuc=palindrommu(mtn,strlen(mtn));
 if (sonuc) printf("Metin palingdrom dur.\n");
 else printf("Metin palingdrom degildir.\n");
 
 printf("\nDevam etmek istermisiniz...?(e/h)");
 kr=getch();
 if (kr=='h'||kr=='H') break;
 }while(1);
 return 0;
}
