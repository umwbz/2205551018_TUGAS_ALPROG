#include <stdio.h>

 void header() {
  printf("=======Menghitung luas segitiga========\n");
  printf("\n");
 }
  
  
void luas() {
  int a, t;
  float luas;
  printf ("Masukkan panjang alas:\n");
  scanf ("%d",&a);
  printf ("Masukkan panjang tinggi:\n");
  scanf ("%d",&t);
  luas = 0.5 * a * t;
  printf("Luas segitiga adalah = %.2f \n", luas);
}
 
int main(void){
  header();
  luas();
   return 0;
}
