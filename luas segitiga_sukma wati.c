#include <stdio.h>

 
void luas() {
  int a, t;
  float luas;
  printf ("Masukkan panjang alas:\n");
  scanf ("%d",&a);
  printf ("Masukkan panjang tinggi:\n");
  scanf ("%d",&t);
  printf("Luas segitiga adalah: %.2f \n",luas);
}
 
int main(void){
  luas();
   return 0;
}
