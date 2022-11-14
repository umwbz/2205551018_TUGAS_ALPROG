#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define adm 10.00
#define bpm 20.00

void header(){
    printf("|======================================================|\n");
    printf("|------------PROGRAM PERHITUNGAN TAGIHAN PDAM----------|\n");
    printf("|======================================================|\n");
}

void clean(){
    while(getchar() != '\n');
}

int validasi(float *var, char nama[100])
{
    if (scanf("%f", var) != 1)
    {
        clean();
        printf("Hanya masukkan angka!, masukkan ulang %s! : ", nama);
        validasi(var, nama);
    }
    return 0;
}

int valid(int x){

    double pil = 0;
    int hasil;
    int i = 0;

    do{
        pil = scanf("%d", &hasil);
        while (getchar()!='\n'){
            /* tidak ada proses*/
        }
        
        if (pil == 0 || hasil > 31|| hasil < 1){
            printf("INPUT SALAH!!M MASUKKAN  ULANG !! ");
        }
        else{
            i = 1;
        }
        
    }while (i != 1);

    return hasil;
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

int menu (){
    int gol, tanggal, no_rek;
    float bulan_ini, bulan_lalu, pemakaian, biaya, sisa, denda, total;
    char nam;
    char nama[100];
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
    scanf("%i", &gol);

    switch (gol){
    case 1 :
        system ("cls");
	    puts("\n\t=======================================================");
        puts("\n\t||              GOLONGAN 2A                          ||");
        puts("\n\t=======================================================");
        printf("\tMasukkan nama Anda : ");
        scanf("%s", &nam);
        printf("\tMasukkan no rekening :");
        strcpy(nama, "no rekening");
        validasi(&no_rek, nama);
        printf("\tMasukkan tanggal pembayaran : ");
        tanggal = valid(0);
        printf("\tinput pemakaian air bulan ini (m3) :");
        scanf( "%f", &bulan_ini);
        printf("\tInput pemakaian air bulan lalu (m3) :");
        scanf("%f", &bulan_lalu);
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
        printf("\n\t=======================================================");
        printf("\n\t||           T A G I H A N   P D A M                 ||");
        printf("\n\t||                 GOLONGAN 2A                       ||");
        printf("\n\t=======================================================");
        printf("\n\t GOLONGAN                   : 2A ");
        printf("\n\t Nama                       : %s", nama);
        printf("\n\t no rek. PDAM               : %d", no_rek);
        printf("\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
        printf("\n\t Tanggal pembayaran         : %d", tanggal);
        printf("\n\t Biaya Administrasi         : Rp. %.2f", adm);
        printf("\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
        printf("\n\t Denda                      : Rp. %.2f", denda);
        printf("\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
        printf("\n\t=======================================================");
        total = adm + bpm + biaya + denda;
        printf("\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
        break;
    case 2 : 
        system ("cls");
	    puts("\n\t=======================================================");
        puts("\n\t||              GOLONGAN 2B                          ||");
        puts("\n\t=======================================================");
        printf("\tMasukkan nama Anda : ");
        scanf("%s", &nam);
        printf("\tMasukkan no rekening :");
        strcpy(nama, "no rekening");
        validasi(&no_rek, nama);
        printf("\tMasukkan tanggal pembayaran : ");
        tanggal = valid(0);
        printf("\tinput pemakaian air bulan ini (m3) :");
        scanf( "%f", &bulan_ini);
        printf("\tInput pemakaian air bulan lalu (m3) :");
        scanf("%f", &bulan_lalu);
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
        printf("\n\t=======================================================");
        printf("\n\t||           T A G I H A N   P D A M                 ||");
        printf("\n\t||                 GOLONGAN 2A                       ||");
        printf("\n\t=======================================================");
        printf("\n\t GOLONGAN                   : 2A ");
        printf("\n\t Nama                       : %s", nama);
        printf("\n\t no rek. PDAM               : %d", no_rek);
        printf("\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
        printf("\n\t Tanggal pembayaran         : %d", tanggal);
        printf("\n\t Biaya Administrasi         : Rp. %.2f", adm);
        printf("\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
        printf("\n\t Denda                      : Rp. %.2f", denda);
        printf("\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
        printf("\n\t=======================================================");
        total = adm + bpm + biaya + denda;
        printf("\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
        break;
    case 3 :
        system ("cls");
	    puts("\n\t=======================================================");
        puts("\n\t||              GOLONGAN 3A                          ||");
        puts("\n\t=======================================================");
        printf("\tMasukkan nama Anda : ");
        scanf("%s", &nam);
        printf("\tMasukkan no rekening :");
        strcpy(nama, "no rekening");
        validasi(&no_rek, nama);
        printf("\tMasukkan tanggal pembayaran : ");
        tanggal = valid(0);
        printf("\tinput pemakaian air bulan ini (m3) :");
        scanf( "%f", &bulan_ini);
        printf("\tInput pemakaian air bulan lalu (m3) :");
        scanf("%f", &bulan_lalu);
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
        printf("\n\t=======================================================");
        printf("\n\t||           T A G I H A N   P D A M                 ||");
        printf("\n\t||                 GOLONGAN 3A                       ||");
        printf("\n\t=======================================================");
        printf("\n\t GOLONGAN                   : 3A ");
        printf("\n\t Nama                       : %s", nama);
        printf("\n\t no rek. PDAM               : %d", no_rek);
        printf("\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
        printf("\n\t Tanggal pembayaran         : %d", tanggal);
        printf("\n\t Biaya Administrasi         : Rp. %.2f", adm);
        printf("\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
        printf("\n\t Denda                      : Rp. %.2f", denda);
        printf("\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
        printf("\n\t=======================================================");
        total = adm + bpm + biaya + denda;
        printf("\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
        break;
    case 4 :
        system ("cls");
	    puts("\n\t=======================================================");
        puts("\n\t||              GOLONGAN 3B                          ||");
        puts("\n\t=======================================================");
        printf("\tMasukkan nama Anda : ");
        scanf("%s", &nam);
        printf("\tMasukkan no rekening :");
        strcpy(nama, "no rekening");
        validasi(&no_rek, nama);
        printf("\tMasukkan tanggal pembayaran : ");
        tanggal = valid(0);
        printf("\tinput pemakaian air bulan ini (m3) :");
        scanf( "%f", &bulan_ini);
        printf("\tInput pemakaian air bulan lalu (m3) :");
        scanf("%f", &bulan_lalu);
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
        printf("\n\t=======================================================");
        printf("\n\t||           T A G I H A N   P D A M                 ||");
        printf("\n\t||                 GOLONGAN 3B                       ||");
        printf("\n\t=======================================================");
        printf("\n\t GOLONGAN                   : 3B");
        printf("\n\t Nama                       : %s", nama);
        printf("\n\t no rek. PDAM               : %d", no_rek);
        printf("\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
        printf("\n\t Tanggal pembayaran         : %d", tanggal);
        printf("\n\t Biaya Administrasi         : Rp. %.2f", adm);
        printf("\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
        printf("\n\t Denda                      : Rp. %.2f", denda);
        printf("\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
        printf("\n\t=======================================================");
        total = adm + bpm + biaya + denda;
        printf("\n\t TOTAL TAGIHAN              :Rp.%.2f", total);
        break;
    case 5 :
        system ("cls");
	    puts("\n\t=======================================================");
        puts("\n\t||              GOLONGAN 3C                          ||");
        puts("\n\t=======================================================");
        printf("\tMasukkan nama Anda : ");
        scanf("%s", &nam);
        printf("\tMasukkan no rekening :");
        strcpy(nama, "no rekening");
        validasi(&no_rek, nama);
        printf("\tMasukkan tanggal pembayaran : ");
        tanggal = valid(0);
        printf("\tinput pemakaian air bulan ini (m3) :");
        scanf( "%f", &bulan_ini);
        printf("\tInput pemakaian air bulan lalu (m3) :");
        scanf("%f", &bulan_lalu);
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
        printf("\n\t=======================================================");
        printf("\n\t||           T A G I H A N   P D A M                 ||");
        printf("\n\t||                 GOLONGAN 3C                       ||");
        printf("\n\t=======================================================");
        printf("\n\t GOLONGAN                   : 3C ");
        printf("\n\t Nama                       : %s", nama);
        printf("\n\t no rek. PDAM               : %d", no_rek);
        printf("\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
        printf("\n\t Tanggal pembayaran         : %d", tanggal);
        printf("\n\t Biaya Administrasi         : Rp. %.2f", adm);
        printf("\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
        printf("\n\t Denda                      : Rp. %.2f", denda);
        printf("\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
        printf("\n\t=======================================================");
        total = adm + bpm + biaya + denda;
        printf("\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
        break;
    case 6 :
        system ("cls");
	    puts("\n\t=======================================================");
        puts("\n\t||              GOLONGAN 4A                          ||");
        puts("\n\t=======================================================");
        printf("\tMasukkan nama Anda : ");
        scanf("%s", &nam);
        printf("\tMasukkan no rekening :");
        strcpy(nama, "no rekening");
        validasi(&no_rek, nama);
        printf("\tMasukkan tanggal pembayaran : ");
        tanggal = valid(0);
        printf("\tinput pemakaian air bulan ini (m3) :");
        scanf( "%f", &bulan_ini);
        printf("\tInput pemakaian air bulan lalu (m3) :");
        scanf("%f", &bulan_lalu);
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
        printf("\n\t=======================================================");
        printf("\n\t||           T A G I H A N   P D A M                 ||");
        printf("\n\t||                 GOLONGAN 4A                       ||");
        printf("\n\t=======================================================");
        printf("\n\t GOLONGAN                   : 4A ");
        printf("\n\t Nama                       : %s", nama);
        printf("\n\t no rek. PDAM               : %d", no_rek);
        printf("\n\t Jumlah pemakaian  (m3)     : %.2f",pemakaian);
        printf("\n\t Tanggal pembayaran         : %d", tanggal);
        printf("\n\t Biaya Administrasi         : Rp. %.2f", adm);
        printf("\n\t Biaya pemeliharaan         : Rp. %.2f", bpm);
        printf("\n\t Denda                      : Rp. %.2f", denda);
        printf("\n\t Biaya pemakaian(bulan ini) : Rp. %.2f", biaya);
        printf("\n\t=======================================================");
        total = adm + bpm + biaya + denda;
        printf("\n\t TOTAL TAGIHAN              : Rp.%.2f", total);
        break;
    default:
        break;
    }
    return 0;
}
