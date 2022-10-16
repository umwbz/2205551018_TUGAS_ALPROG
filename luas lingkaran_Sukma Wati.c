#include <stdio.h>

 
void luas() {
  float pi, r, luas;
  pi=3.14;
  printf ("Masukkan jari-jari:\n");
  scanf ("%f",&r);
  luas = 3.14 * r * r;
  printf("Luas segitiga adalah: %.2f \n",luas);
}
 
int main(void){
  luas();
   return 0;
}
