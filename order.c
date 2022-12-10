/*[TUGAS BESAR ALPROG] (SUKMA WATI (2205551018) DAN ANATSHIA MUNTHE (2205551047)) */ 
/*PROGRAM PEMESANAN MENU DI RESTORAN REFERENCE https://harga.web.id/info-lengkap-daftar-harga-menu-makanan-minuman-di-mcdonalds-mcd.info*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ppn  0.10

int main(){
	
	char username [15];
	char password [8];
	
	system ("cls");
	printf("\n\t======================================================\n");
	printf("\n\t||                     ANNYEONG >_<                 ||\n");
	printf("\n\t||            SILAHKAH LOG IN TERLEBIH DAHULU       ||\n");
	printf("\n\t||====================================================\n");
	printf("\n\t  Masukkan username     :");
	scanf("%s", username);
	printf("\n\t  Masukkan password     :");
	scanf("%s", password);
	if ((strcmp(username, "admin") == 0) && (strcmp(password, "mcd") ==0)){
		order();
		
	}else {
		printf("\n\t  PASSWORD atau USERNAME SALAH!");
		
	}
	return 0;
}

void ending(){
    system ("cls");
    printf ("|----------------------------------|\n");
    printf ("|==KAMSAHAMNIDA ATAS KUNJUNGANNYA==|\n");
    printf ("|------------ANNYEONG >_< ---------|\n");
    printf ("|----------------------------------|\n");
}
void menu(){
    system("cls");
    printf("==============================================================\n");
    printf("|---------------DAFTAR MENU MCDONALD'S(MCD)------------------|\n");
    printf("|-------------------------JIMBARAN---------------------------|\n");
    printf("|---------------------JL.KAMPUS UNUD-------------------------|\n");
    printf("|                                                            |\n");
    printf("|------------------------------------------------------------|\n");
    printf("|   Menu Ala carte McD                |                HARGA |\n");
    printf("|------------------------------------------------------------|\n");
    printf("|1.Bubur Ayam McD 	                                 Rp11.500|\n");
    printf("|2.McFlurry Featuring Oreo                     	     Rp11.500|\n");
    printf("|3.McFlurry Choco 	                                 Rp11.500|\n");
    printf("|4.Coke McFloat 	                                 Rp12.000|\n");
    printf("|5.Fanta McFloat                                     Rp12.000|\n");
    printf("|6.Tiramisu McFlurry with Biscoff 	                 Rp16.000|\n");
    printf("|7.Tiramisu McFlurry with Oreo 	                     Rp16.000|\n");
    printf("|8.Nasi Uduk McD 	                                 Rp18.500|\n");
    printf("|------------------------------------------------------------|\n");
    printf("|   Menu paket McD                    |                HARGA |\n");
    printf("|------------------------------------------------------------|\n");
    printf("|9.Hotcakes 2 pcs 	                                 Rp22.000|\n");
    printf("|10.Sausage Wrap 	                                 Rp22.000|\n");
    printf("|11.Hotcakes 3 pcs 	                                 Rp27.000|\n");
    printf("|12.Mini Cuts Spicy Chicken 	                     Rp36.000|\n");
    printf("|13.Happy Meal Egg & Cheese Muffin 	                 Rp37.500|\n");
    printf("|14.Pamer 5 Ayam Gulai McD 	                        Rp110.500|\n");
    printf("|15.Happy Meal Ayam 	                             Rp37.500|\n");
    printf("|-------------------------exit 0-----------------------------|\n");
    printf("==============================================================\n");
   
}

int validasi(int x){
    double pil = 5;
    int hasil;
    int i = 0;

    do{
        pil = scanf("%d", &hasil);
        if (pil < 1){   
            getchar();
            printf(" INPUT SALAH!!PILIH ULANG YA!! ");
            printf("==> pilih :");
        }
        else if (x == 1){
            if (hasil > 1 || hasil < 0){
                printf("INPUT SALAH!!PILIH ULANG YA!! ");
                printf("==> pilih (0/1):");
            }
            else {
                i = 1;
            }  
        }
        else if (x == 2) {
            if (hasil > 15 || hasil < 0){
                printf("INPUT SALAH!!PILIH ULANG YA!! ");
                printf("==> pilih (1-3):");
            }
            else{
                i = 1;
            }
        }
        else{
            i = 1;
        } 
    } while (i != 1);

    return hasil;
}

int order(){
    int pil, jumlah, makanan, total, bayar, kurang, bonus, pajak, kembalian,saldo,
        harga[9] ={11500, 12000, 16000, 18500, 22000, 27000, 36000, 37500, 110500}, i=0;
    char nama[50],food[50], ulang;

    system("cls");
    menu();
    printf("masukkan pilihan menu:");
    pil = validasi(2);
    if (pil !=0){
        printf("Masukan nama pemesan: \n");
        scanf("%s",&nama);
    }else{
        ending();
    }  

    switch(pil){
        case 1 :
            strcpy(food, "Bubur ayam McD");
            break;
        case 2 :
            strcpy(food, "McFlurry Featuring Oreo ");
            break;
        case 3 :
            strcpy(food,"McFlurry Choco " );
            break;
        case 4 :
            strcpy(food,"Coke McFloat ");
            i = 1;
        break;
        case 5 :
            strcpy(food, "Fanta McFloat   ");
            i = 1;
        break;
        case 6 :
            strcpy(food, "iramisu McFlurry with Biscoff ");
            i = 2;
        break;
        case 7:
            strcpy(food, "Tiramisu McFlurry with Oreo 	 ");
            i = 2;
        break;
        case 8:
            strcpy(food, "Nasi Uduk McD 	 ");
            i = 3;
        break;
        case 9:
            strcpy(food, "Hotcakes 2 pcs	 ");
            i = 4;
        break;
        case 10:
            strcpy(food, "Sausage Wrap 	 ");
            i = 4;
        break;
        case 11:
            strcpy(food, "Hotcakes 3 pcs	 ");
            i = 5;
        break;
        case 12:
            strcpy(food, "Mini Cuts Spicy Chicken 	 ");
            i = 6;
        break;
        case 13:
            strcpy(food, "Happy Meal Egg & Cheese Muffin 		 ");
            i = 7;
        break;
        case 14:
            strcpy(food, "Pamer 5 Ayam Gulai McD 	 ");
            i = 8;
        break;
        case 15:
            strcpy(food, "Happy Meal Ayam 	 ");
            i = 9;
        break;
        default :
        printf("input salah!!");
        break;
    }
    printf("masukkan jumlah pesananm :");
    scanf("%d", &jumlah);

    makanan = jumlah + harga[i];
    pajak = makanan + ppn;
    total = pajak + makanan;
    printf("total  harus dibayar   : Rp. %d\n", total);
    printf ("masukkan uang pembayarn :\n");
    scanf("%d", &bayar);
    if (bayar < total){
        printf ("SILHKAN BAYAR SESUAI DENGAN TOTAL PEMBAYARRNA !");
    }
    else{
        kembalian = bayar- total;
    }
    system("cls");
    printf("\n\t=======================================================");
    printf("\n\t||                   STRUK PEMBAYARAN                ||");
    printf("\n\t||                      MCDONALDS'                   ||");
    printf("\n\t=======================================================");
    printf("\n\t Nama pemesan                    : %s", nama);
    printf("\n\t menu pesaanan                   : %s", food);
    printf("\n\t Jumlah pesanan                  : %d",jumlah);
    printf("\n\t harga menu                      : Rp. %d",jumlah * harga[i]);
    printf("\n\t pajak                           : Rp. %d",pajak);
    printf("\n\t TOTAL TAGIHAN                   : Rp. %d", total);
    printf("\n\t Jumlah Uang Pembayaran          : Rp. %d",bayar);
    printf("\n\t Kembalian                       : Rp. %d",kembalian);
    printf("\n\t=======================================================");

   

    return 0;
    
}
