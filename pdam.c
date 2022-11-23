#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define adm 10.00
#define bpm 20.00

void header(){
    printf("|======================================================|\n");
    printf("|------------PROGRAM PERHITUNGAN TAGIHAN PDAM----------|\n");
    printf("|======================================================|\n");
}

void ending(){
    system ("cls");
    printf ("|----------------------------------|\n");
    printf ("|==KAMSAHAMNIDA ATAS KUNJUNGANNYA==|\n");
    printf ("|------------ANNYEONG >_< ---------|\n");
    printf ("|----------------------------------|\n");

    exit (0);
}
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
	if ((strcmp(username, "admin") == 0) && (strcmp(password, "pdam") ==0)){
		menu();
		
	}else {
		printf("\n\t  PASSWORD atau USERNAME SALAH!");
		
	}
	return 0;
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
        else if(x == 2){
            if (hasil > 6 || hasil < 1){
               printf("INPUT SALAH!!PILIH ULANG YA!! ");
                printf("==> pilih (1-6):");
            }
            else{
                i = 1;
            }
        }
        else if (x == 5)
        {
            if (hasil > 31|| hasil < 1){
                printf("INPUT SALAH!!MASUKKAN ULANG!! ");
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

int menu (){
    int gol;
    system("cls");
    header();
    printf("|======================================================|\n");
    printf("|      Pilihan Golongan Pengguna :                     |\n"); 
    printf("|          [1]. Golongan 2A                            |\n");
    printf("|          [2]. Golongan 2B                            |\n");
    printf("|          [3]. Golongan 3A                            |\n");
    printf("|          [4]. Golongan 3B                            |\n");
    printf("|          [5]. Golongan 3C                            |\n");
    printf("|          [6]. Golongan 4A                            |\n");
    printf("|======================================================|\n");
    printf("\tMasukkan golongan pengguna :");
    gol = validasi(2);

    if (gol==1){
		A2();
	}else if(gol==2){
		B2();
	}else if(gol==3){
		A3();
	}else if(gol==4){
		B3();
	}else if(gol==5){
		C3();
	}else{
		A4();
    }
}
 
int A2 (){
	int tanggal,rek;
    float bulan_ini, bulan_lalu, pemakaian, biaya, sisa, denda, total;
	char nama[50];
	char ulang;
    FILE *fptr = fopen("pdam.txt", "w");
	
	system ("cls");
	printf("\n\t=======================================================");
    printf("\n\t||             GOLONGAN 2A                           ||");
    printf("\n\t=======================================================");
    printf("\n\t Masukkan nama pelanggan   :");
    scanf("%s", &nama);
    printf("\n\t Masukkan nomor rek. PDAM  :");
    rek = validasi(0);
	printf("\n\t Masukkan tanggal pembayaran   :");
    tanggal = validasi(5);
    printf("\n\t Masukan Besar Pemakaian Bulan Sebelumnya (m^3)    :");
    scanf("f",&bulan_lalu);
    printf("\n\t Masukan Besar Pemakaian Saat Ini (m^3)  :");
    scanf("f",&bulan_ini);
    pemakaian = bulan_ini - bulan_lalu;
    printf("\tjumlah pemakaian meter kubik air : %.2f m3", pemakaian);
            if (pemakaian > 10 || pemakaian <= 20){
                sisa = pemakaian - 10;
                biaya = 600.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian <= 10 || pemakaian >= 0){
                biaya = 350.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian > 30){
                biaya = 1800.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else {
                biaya = 0;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
    system("cls");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t||           T A G I H A N   P D A M                 ||");
    fprintf(fptr,"\n\t||                 GOLONGAN 2A                       ||");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t GOLONGAN                   : 2A ");
    fprintf(fptr,"\n\t Nama                       : %s", nama);
    fprintf(fptr,"\n\t no rek. PDAM               : %d", rek);
    fprintf(fptr,"\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
    fprintf(fptr,"\n\t Tanggal pembayaran         : %d", tanggal);
    fprintf(fptr,"\n\t Biaya Administrasi         : Rp. %.2f", adm);
    fprintf(fptr,"\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
    fprintf(fptr,"\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
    fprintf(fptr,"\n\t=======================================================");
    total = adm + bpm + biaya + denda;
    fprintf(fptr,"\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
    fclose(fptr);
    printf("Apakah ingin mencoba kembali (y/n) ?");
    printf("1. ya\n");
    printf("0. no\n");
    printf("pilih : \n");
    ulang = validasi(1);

    if (ulang == 1){
        main();
    }
    else{
        ending();
    }  
     return 0;
}
int B2 (){
	int tanggal,rek;
    float bulan_ini, bulan_lalu, pemakaian, biaya, sisa, denda, total;
	char nama[50];
	char ulang;
	FILE *fptr = fopen("pdam.txt", "w");
	system ("cls");
	printf("\n\t=======================================================");
    printf("\n\t||             GOLONGAN 2B                           ||");
    printf("\n\t=======================================================");
    printf("\n\t Masukkan nama pelanggan   :");
    scanf("%s", &nama);
    printf("\n\t Masukkan nomor rek. PDAM  :");
    rek = validasi(0);
	printf("\n\t Masukkan tanggal pembayaran   :");
    tanggal = validasi(5);
    printf("\n\t Masukan Besar Pemakaian Bulan Sebelumnya (m^3)    :");
    scanf(".2f",&bulan_lalu);
    printf("\n\t Masukan Besar Pemakaian Saat Ini (m^3)  :");
    scanf(".2f",&bulan_ini);
    pemakaian = bulan_ini - bulan_lalu;
    printf("\tjumlah pemakaian meter kubik air : %.2f m3", pemakaian);
        if (pemakaian > 10 || pemakaian <= 20){
            sisa = pemakaian - 10;
            biaya = 1000.00 + sisa * 10.00;
            printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
        }
        else if (pemakaian <= 10 || pemakaian >= 0){
            biaya = 500.00;
            printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
        }
        else if (pemakaian > 20){
            biaya = 2250.00 + sisa * 10.00;
            printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
        }
        else {
            biaya = 0;
            printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
        }
        
        if (pemakaian > 20)
        {
            denda = 20.00;
        }
        else if (pemakaian < 10)
        {
            denda = 10.00;
        }
        else {
            denda = 0; 
        }
    system("cls");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t||           T A G I H A N   P D A M                 ||");
    fprintf(fptr,"\n\t||                 GOLONGAN 2B                       ||");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t GOLONGAN                   : 2B ");
    fprintf(fptr,"\n\t Nama                       : %s", nama);
    fprintf(fptr,"\n\t no rek. PDAM               : %d", rek);
    fprintf(fptr,"\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
    fprintf(fptr,"\n\t Tanggal pembayaran         : %d", tanggal);
    fprintf(fptr,"\n\t Biaya Administrasi         : Rp. %.2f", adm);
    fprintf(fptr,"\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
    fprintf(fptr,"\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
    fprintf(fptr,"\n\t=======================================================");
    total = adm + bpm + biaya + denda;
    fprintf(fptr,"\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
    fclose(fptr);

    printf("Apakah ingin mencoba kembali (y/n) ?\n");
    printf("1. ya\n");
    printf("0. no\n");
    printf("pilih : \n");
    ulang = validasi(1);

    if (ulang == 1){
        main();
    }
    else{
        ending();
    }  

    return 0;
}

int A3(){
	int tanggal,rek;
    float bulan_ini, bulan_lalu, pemakaian, biaya, sisa, denda, total;
	char nama[50];
	char ulang;
	FILE *fptr = fopen("pdam.txt","w");
	system ("cls");
	printf("\n\t=======================================================");
    printf("\n\t||             GOLONGAN 3A                           ||");
    printf("\n\t=======================================================");
    printf("\n\t Masukkan nama pelanggan   :");
    scanf("%s", &nama);
    printf("\n\t Masukkan nomor rek. PDAM  :");
    rek = validasi(0);
	printf("\n\t Masukkan tanggal pembayaran   :");
    tanggal = validasi(5);
    printf("\n\t Masukan Besar Pemakaian Bulan Sebelumnya (m^3)    :");
    scanf("f",&bulan_lalu);
    printf("\n\t Masukan Besar Pemakaian Saat Ini (m^3)  :");
    scanf("f",&bulan_ini);
    pemakaian = bulan_ini - bulan_lalu;
    printf("\tjumlah pemakaian meter kubik air : %.2f m3", pemakaian);

            if (pemakaian > 10 || pemakaian <= 20){
                sisa = pemakaian - 10;
                biaya = 1200.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian <= 10 || pemakaian >= 0){
                biaya = 500.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian > 30){
                biaya = 1900.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else {
                biaya = 0;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            
            if (pemakaian > 20)
            {
                denda = 20.00;
            }
            else if (pemakaian < 10)
            {
                denda = 10.00;
            }
            else {
                denda = 0; 
            }
    system("cls");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t||           T A G I H A N   P D A M                 ||");
    fprintf(fptr,"\n\t||                 GOLONGAN 3A                       ||");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t GOLONGAN                   : 3A ");
    fprintf(fptr,"\n\t Nama                       : %s", nama);
    fprintf(fptr,"\n\t no rek. PDAM               : %d", rek);
    fprintf(fptr,"\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
    fprintf(fptr,"\n\t Tanggal pembayaran         : %d", tanggal);
    fprintf(fptr,"\n\t Biaya Administrasi         : Rp. %.2f", adm);
    fprintf(fptr,"\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
    fprintf(fptr,"\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
    fprintf(fptr,"\n\t=======================================================");
    total = adm + bpm + biaya + denda;
    fprintf(fptr,"\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
    fclose(fptr);


    printf("Apakah ingin mencoba kembali (y/n) ?\n");
    printf("1. ya\n");
    printf("0. no\n");
    printf("pilih : \n");
    ulang = validasi(1);

    if (ulang == 1){
        main();
    }
    else{
        ending();
    }  

    return 0;
}
int B3(){
	int tanggal,rek;
    float bulan_ini, bulan_lalu, pemakaian, biaya, sisa, denda, total;
	char nama[50];
	char ulang;
	FILE *fptr = fopen("pdam.txt", "w");
	system ("cls");
	printf("\n\t=======================================================");
    printf("\n\t||             GOLONGAN 3B                           ||");
    printf("\n\t=======================================================");
    printf("\n\t Masukkan nama pelanggan   :");
    scanf("%s", &nama);
    printf("\n\t Masukkan nomor rek. PDAM  :");
    rek = validasi(0);
	printf("\n\t Masukkan tanggal pembayaran   :");
    tanggal = validasi(5);
    printf("\n\t Masukan Besar Pemakaian Bulan Sebelumnya (m^3)    :");
    scanf("f",&bulan_lalu);
    printf("\n\t Masukan Besar Pemakaian Saat Ini (m^3)  :");
    scanf("f",&bulan_ini);
    pemakaian = bulan_ini - bulan_lalu;
    printf("\tjumlah pemakaian meter kubik air : %.2f m3", pemakaian);
            if (pemakaian > 10 || pemakaian <= 20){
                sisa = pemakaian - 10;
                biaya = 3500.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian <= 10 || pemakaian >= 0){
                biaya = 1500.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian > 20){
                biaya = 6000.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else {
                biaya = 0;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            
            if (pemakaian > 20)
            {
                denda = 20.00;
            }
            else if (pemakaian < 10)
            {
                denda = 10.00;
            }
            else {
                denda = 0; 
            }
    
    system("cls");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t||           T A G I H A N   P D A M                 ||");
    fprintf(fptr,"\n\t||                 GOLONGAN 3B                       ||");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t GOLONGAN                   : 3B ");
    fprintf(fptr,"\n\t Nama                       : %s", nama);
    fprintf(fptr,"\n\t no rek. PDAM               : %d", rek);
    fprintf(fptr,"\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
    fprintf(fptr,"\n\t Tanggal pembayaran         : %d", tanggal);
    fprintf(fptr,"\n\t Biaya Administrasi         : Rp. %.2f", adm);
    fprintf(fptr,"\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
    fprintf(fptr,"\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
    fprintf(fptr,"\n\t=======================================================");
    total = adm + bpm + biaya + denda;
    fprintf(fptr,"\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
    fclose(fptr);

    printf("Apakah ingin mencoba kembali (y/n) ?\n");
    printf("1. ya\n");
    printf("0. no\n");
    printf("pilih : \n");
    ulang = validasi(1);

    if (ulang == 1){
        main();
    }
    else{
        ending();
    }  

    return 0;
}
int C3 (){
	int tanggal,rek;
    float bulan_ini, bulan_lalu, pemakaian, biaya, sisa, denda, total;
	char nama[50];
	char ulang;
	FILE *fptr = fopen("pdam.txt", "w");

	system ("cls");
	printf("\n\t=======================================================");
    printf("\n\t||             GOLONGAN 3C                           ||");
    printf("\n\t=======================================================");
    printf("\n\t Masukkan nama pelanggan   :");
    scanf("%s", &nama);
    printf("\n\t Masukkan nomor rek. PDAM  :");
    rek = validasi(0);
	printf("\n\t Masukkan tanggal pembayaran   :");
    tanggal = validasi(5);
    printf("\n\t Masukan Besar Pemakaian Bulan Sebelumnya (m^3)    :");
    scanf("f",&bulan_lalu);
    printf("\n\t Masukan Besar Pemakaian Saat Ini (m^3)  :");
    scanf("f",&bulan_ini);
    pemakaian = bulan_ini - bulan_lalu;
    printf("\tjumlah pemakaian meter kubik air : %.2f m3", pemakaian);
            if (pemakaian > 10 || pemakaian <= 20){
                sisa = pemakaian - 10;
                biaya = 4000.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian <= 10 || pemakaian >= 0){
                biaya = 2300.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian > 20){
                biaya = 5500.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else {
                biaya = 0;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            
            if (pemakaian > 20)
            {
                denda = 20.00;
            }
            else if (pemakaian < 10)
            {
                denda = 10.00;
            }
            else {
                denda = 0; 
            }
    system("cls");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t||           T A G I H A N   P D A M                 ||");
    fprintf(fptr,"\n\t||                 GOLONGAN 3C                      ||");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t GOLONGAN                   : 3C ");
    fprintf(fptr,"\n\t Nama                       : %s", nama);
    fprintf(fptr,"\n\t no rek. PDAM               : %d", rek);
    fprintf(fptr,"\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
    fprintf(fptr,"\n\t Tanggal pembayaran         : %d", tanggal);
    fprintf(fptr,"\n\t Biaya Administrasi         : Rp. %.2f", adm);
    fprintf(fptr,"\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
    fprintf(fptr,"\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
    fprintf(fptr,"\n\t=======================================================");
    total = adm + bpm + biaya + denda;
    fprintf(fptr,"\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
    fclose(fptr);

    printf("Apakah ingin mencoba kembali (y/n) ?\n");
    printf("1. ya\n");
    printf("0. no\n");
    printf("pilih : \n");
    ulang = validasi(1);

    if (ulang == 1){
        main();
    }
    else{
        ending();
    }  

    return 0;
}
int A4 (){
	int tanggal,rek;
    float bulan_ini, bulan_lalu, pemakaian, biaya, sisa, denda, total;
	char nama[50];
	char ulang;
	FILE *fptr = fopen("pdam.txt", "w");
    
	system ("cls");
	printf("\n\t=======================================================");
    printf("\n\t||             GOLONGAN 4A                           ||");
    printf("\n\t=======================================================");
    printf("\n\t Masukkan nama pelanggan   :");
    scanf("%s", &nama);
    printf("\n\t Masukkan nomor rek. PDAM  :");
    rek = validasi(0);
	printf("\n\t Masukkan tanggal pembayaran   :");
    tanggal = validasi(5);
    printf("\n\t Masukan Besar Pemakaian Bulan Sebelumnya (m^3)    :");
    scanf("f",&bulan_lalu);
    printf("\n\t Masukan Besar Pemakaian Saat Ini (m^3)  :");
    scanf("f",&bulan_ini);
    pemakaian = bulan_ini - bulan_lalu;
    printf("\tjumlah pemakaian meter kubik air : %.2f m3", pemakaian);

           if (pemakaian > 10 || pemakaian <= 20){
                sisa = pemakaian - 10;
                biaya = 1500.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian <= 10 || pemakaian >= 0){
                biaya = 1000.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else if (pemakaian > 20){
                biaya = 2500.00 + sisa * 10.00;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            else {
                biaya = 0;
                printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
            }
            
            if (pemakaian > 20)
            {
                denda = 20.00;
            }
            else if (pemakaian < 10)
            {
                denda = 10.00;
            }
            else {
                denda = 0; 
            }
    system("cls");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t||           T A G I H A N   P D A M                 ||");
    fprintf(fptr,"\n\t||                 GOLONGAN 4A                       ||");
    fprintf(fptr,"\n\t=======================================================");
    fprintf(fptr,"\n\t GOLONGAN                   : 4A ");
    fprintf(fptr,"\n\t Nama                       : %s", nama);
    fprintf(fptr,"\n\t no rek. PDAM               : %d", rek);
    fprintf(fptr,"\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
    fprintf(fptr,"\n\t Tanggal pembayaran         : %d", tanggal);
    fprintf(fptr,"\n\t Biaya Administrasi         : Rp. %.2f", adm);
    fprintf(fptr,"\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
    fprintf(fptr,"\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
    fprintf(fptr,"\n\t=======================================================");
    total = adm + bpm + biaya + denda;
    fprintf(fptr,"\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
    fclose(fptr);

    printf("Apakah ingin mencoba kembali (y/n) ?\n");
    printf("1. ya\n");
    printf("0. no\n");
    printf("pilih : \n");
    ulang = validasi(1);

    if (ulang == 1){
        main();
    }
    else{
        ending();
    }  

    return 0;
}
