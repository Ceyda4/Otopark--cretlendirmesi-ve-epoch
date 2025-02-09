#include <stdio.h>
#include <time.h>

#define ILK_SAAT_UCRET 20
#define SONRAKI_SAAT_UCRET 10

time_t tarihToEpoch(int gun, int ay, int yil, int saat, int dakika, int saniye) {
    struct tm zamanStruct = {0};
    zamanStruct.tm_year = yil - 1900;
    zamanStruct.tm_mon = ay - 1;
    zamanStruct.tm_mday = gun;
    zamanStruct.tm_hour = saat;
    zamanStruct.tm_min = dakika;
    zamanStruct.tm_sec = saniye;
    return mktime(&zamanStruct);
}

int main() {
    int girisGun, girisAy, girisYil, girisSaat, girisDakika, girisSaniye;
    int cikisGun, cikisAy, cikisYil, cikisSaat, cikisDakika, cikisSaniye;

    printf("Arac giris zamanini girin (GG AA YYYY SS:DD:SS): ");
    scanf("%d %d %d %d:%d:%d", &girisGun, &girisAy, &girisYil, &girisSaat, &girisDakika, &girisSaniye);

    printf("Arac cikis zamanini girin (GG AA YYYY SS:DD:SS): ");
    scanf("%d %d %d %d:%d:%d", &cikisGun, &cikisAy, &cikisYil, &cikisSaat, &cikisDakika, &cikisSaniye);

    time_t epochGiris = tarihToEpoch(girisGun, girisAy, girisYil, girisSaat, girisDakika, girisSaniye);
    time_t epochCikis = tarihToEpoch(cikisGun, cikisAy, cikisYil, cikisSaat, cikisDakika, cikisSaniye);

    time_t otoparkSuresi = epochCikis - epochGiris; // Toplam süre saniye cinsinden

    int toplamSaat = otoparkSuresi / 3600; // Saniyeyi saate çevir

    // Ücret hesaplama
    int toplamUcret;
    if (toplamSaat == 0) {
        toplamUcret = ILK_SAAT_UCRET;
    } else {
        toplamUcret = ILK_SAAT_UCRET + (toplamSaat - 1) * SONRAKI_SAAT_UCRET;
    }

    printf("\nToplam park suresi: %d saat\n", toplamSaat);
    printf("Odemeniz gereken tutar: %d TL\n", toplamUcret);

    return 0;
}

