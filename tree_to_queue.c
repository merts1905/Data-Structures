//
//
//  Ağaçtan kuyruğa aktaran program
//  Esra Yakut'a teşekkürler
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct dugum {
    int veri;
    struct dugum * sol;
    struct dugum * sag;
} DUGUM;

typedef struct kuyruk {
    int ilk, son;       // Eleman eklerken "son"u kullanıyorum, eleman çıkartırken "ilk"i kullanıyorum.
    // "son", en son eleman eklenmiş indisin numarası; "ilk", ilk eklenmiş elemanın indis numarası
    int dizi[MAX];      // Verilerimi 100 elemanlık bir dizide tutacağım.
} KUYRUK;

void kuyrugaEkle(KUYRUK * kk, int eleman) {
    if (kk->son == MAX - 1)         // Daha önceden kuyruğa eleman eklenmediyse
        kk->son = 0;
    else                            // Daha önceden kuyruğa eleman eklendiyse
        kk->son++;
    // "son"u eleman eklemek için hazırlamış oldum, artık yeni eklenecek elemanın indis gözünü işaret ediyor.
    if (kk->son == kk->ilk) {
        printf("Kuyruk doldugu icin eleman eklenemiyor.");
        exit(1);
    }
    kk->dizi[kk->son] = eleman;
}

void agaciDolasKuyrugaAktar(DUGUM * kokDugum, KUYRUK * kk) {
    if (kokDugum != NULL) {
        kuyrugaEkle(kk, kokDugum->veri);                // DLR formatında
        agaciDolasKuyrugaAktar(kokDugum->sol, kk);
        agaciDolasKuyrugaAktar(kokDugum->sag, kk);
    }
}

int main() {
    DUGUM * agac;       // Daha önceden oluşturulmuş olan bir ağaç. İlgili fonksiyonlar kullanılarak yeni düğümler eklenmiş olduğunu varsayıyoruz.
    KUYRUK kuyruk;                          // Kuyruğumu oluşturdum.
    kuyruk.ilk = kuyruk.son = MAX - 1;      // 99 indis gözünü işaret ediyor, daha veri aktarması yapmadım.
    agaciDolasKuyrugaAktar(agac, &kuyruk);  // "kuyruk"un adresini yolladım, çünkü fonksiyonlarda parametre olarak kalıcı işlem yapabilmek için adreslerini almıştım.
    // Uyarı vermesinin sebebi "agac" şu an sadece bellekte bir gözü temsil ediyor. Soruda önceden hazırlanmış bir ağaç olduğunu varsaymamız gerekiyor.
    return 0;
}
