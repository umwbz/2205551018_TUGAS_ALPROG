#include <stdio.h>
#include <stdlib.h>
#define adm 10.00

int main (){
    int gol;
    float bulan_ini, bulan_lalu, pemakaian, bpm, biaya, sisa, denda, total;
    
    printf("==============================================================\n");
    printf("|----------------TUGAS ALGORITMA PEMROGRAMAN-----------------|\n");
    printf("|-------------------SUKMA WATI & ANASTASIA-------------------|\n");
    printf("|------------PROGRAM PERHITUNGAN TAGIHAN PDAM----------------|\n");
    printf("|                                                            |\n");
    printf("|                  pilih golongan pengguna                   |\n");
    printf("|------------------------------------------------------------|\n");
    printf("|       |            [1]. Rumah tangga                   |   |\n");
    printf("|                    [2]. Usaha                              |\n");
    printf("==============================================================\n");
    printf("Masukkan golongan pengguna :\n");
    scanf("%i", &gol);

        if(gol == 1){
        bpm = 10.00;
        }
        else if (gol == 2){
        bpm = 20.00;
        }
        else {
        printf("INPUT SALAH!!\n");
        exit(1);
        }

    printf(" input pemakaian air bulan ini (m3) :\n");
    scanf( "%f", &bulan_ini);
    printf("Input pemakaian air bulan lalu (m3) :\n");
    scanf("%f", &bulan_lalu);
    pemakaian = bulan_ini - bulan_lalu;
    printf("jumlah pemakaian meter kubik air : %.2f m3\n", pemakaian);

        if (pemakaian > 10){
            sisa = pemakaian - 10;
            biaya = 50.00 + sisa * 10.00;
            printf("Biaya pemakaian bulan ini : Rp %.2f\n", biaya);
        }
        else if (pemakaian <= 10 && pemakaian > 0){
            biaya = 50.00;
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
        else if (pemakaian < 20)
        {
            denda = 10.00;
        }
        else {
            denda = 0; 
        }

    printf("Denda                  : Rp %.2f\n", denda);
    printf("Bpm                    : Rp %.2f\n", bpm);
    printf("Biaya administrasi     : Rp %.2f\n", adm);

    total = adm + bpm + biaya + denda;
    printf("Total                  : Rp   %.2f\n",total);

    return 0;
}