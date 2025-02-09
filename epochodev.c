 #include <stdio.h>
#include <time.h>

// Tarih bilgisini saklayan struct
struct Tarih {
    int gun;
    int ay;
    int yil;
    int saat;
    int dakika;
    int saniye;
};

// Epoch bilgisini hem integer hem de double olarak saklamak için union
union EpochZaman {
    time_t tamSayi;
    double ondalikli;
};

// Struct'ý epoch zamanýna çeviren fonksiyon
time_t tarihToEpoch(struct Tarih t) {
    struct tm zamanStruct = {0};
    zamanStruct.tm_year = t.yil - 1900;
    zamanStruct.tm_mon = t.ay - 1;
    zamanStruct.tm_mday = t.gun;
    zamanStruct.tm_hour = t.saat;
    zamanStruct.tm_min = t.dakika;
    zamanStruct.tm_sec = t.saniye;
    return mktime(&zamanStruct);
}

int main() {
    struct Tarih t1, t2;
    union EpochZaman epoch1, epoch2;
    
    printf("Birinci tarihi girin (GG AA YYYY SS:DD:SS): ");
    scanf("%d %d %d %d:%d:%d", &t1.gun, &t1.ay, &t1.yil, &t1.saat, &t1.dakika, &t1.saniye);
    
    printf("Ikinci tarihi girin (GG AA YYYY SS:DD:SS): ");
    scanf("%d %d %d %d:%d:%d", &t2.gun, &t2.ay, &t2.yil, &t2.saat, &t2.dakika, &t2.saniye);
    
    epoch1.tamSayi = tarihToEpoch(t1);
    epoch2.tamSayi = tarihToEpoch(t2);
    
    printf("\nBirinci tarihin epoch zamani: %ld\n", epoch1.tamSayi);
    printf("Ikinci tarihin epoch zamani: %ld\n", epoch2.tamSayi);
    printf("Iki tarih arasindaki fark (saniye): %ld\n", (epoch2.tamSayi - epoch1.tamSayi));
    
    return 0;
}

