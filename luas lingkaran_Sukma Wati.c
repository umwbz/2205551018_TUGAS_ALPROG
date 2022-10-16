#include <stdio.h>

void header(){
  printf("=========Menghituung luas Lingkaran========\n");
 printf("\n");
}
void luas() {
  float pi, r, luas;
  pi=3.14;
  printf ("Masukkan jari-jari:\n");
  scanf ("%f",&r);
  luas = 3.14 * r * r;
  printf("Luas segitiga adalah: %.2f \n",luas);
}
 
int main(void){
  header();
  luas();
   return 0;
}
