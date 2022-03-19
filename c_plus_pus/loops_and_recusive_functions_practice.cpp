#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//    191307093 - JUDY NDOTONI - NKWAMA

// MAIN METODUNDA CEVAP METOTLARI YORUMLANMIS. YORUM ISARAETLERI KALDIRABILIRSINIZ

/*

1- Aşağıda verilen kod bloğunun çıktısı ne olur? Açıklayarak anlatınız.

void right(int i, int p, int n, int k) {
    cout << i << endl;
    if (n == k) return;
    else right(i + p, p, n + 1, k);
}

void down(int i, int p, int n, int k) {
    if (k == n) cout << i << endl;
    else right(i, p, 1, k);

    if (i == 1) return;
    else down(i/2, p/2, 1, k*2);
}

int main() {
    down(8, 16, 1, 1);
}


Çıkı : 8 4 12 2 6 10 14 1 3 5 7 9 11 13 15

    ||=> Verilen fonksioynlar (down ve right) recursive'dir (Özyineli). Tekrarli işlemler için kullanılır.
    
    - right fonksionu i'den başlayarak p'ler p'ler artarak ((k - n)*p) - i ulaşır. Başka bir deyimle i'ye (k - n) kere p ekler
      Aslında bu fonksion ilerleme anahtari p olan bir matematiksel aritmetik ilerleme dizisidir
    - down fonksionu ise 1'e ulaşana kadar her seferde i ve p iki kata indirerek ve  k ama k iki kata çıkartarak i'den başlayarak yine i'ye p ekleyerek artıyor
      down fonksionu, madem i == 1 şartı ile kendi kendini çağırmayi durdurur ve main()'da i 8 olarak verildiği için ve down()'da her seferde 8 ikiye bölüneceği için,
      son olarak da 2^3=8 (yani log8 2 tabanında eşit 3 ) olduğu için down fonksionu 3 kere  kendi kendini çağıracaktir

      şöyle : down(8, 16, 1, 1)
      1. kere 1 == 1 oldugu için 8 basılacak ekrana
         sonra 8 != 1 oldugu için down(4, 8, 1, 2) çağırılacak
         1 != 2  oldugu için right(4, 8, 1, 2) çağırılacak ve 4 12 basılacak ekrana
      2. kere 4 != 1  oldugu için down(2, 4, 1, 4) çağırılacak
         sonra 4 != 1 oldugu için right(2, 4, 1, 4) çağırılacak ve 2 6 10 14 basılacak ekrana
      3. kere kere 2 != 1  oldugu için down(1, 2, 1, 8) çağırılacak
         sonra 8 != 1 oldugu için right(1, 2, 1, 8) çağırılacak ve 1 3 5 7 9 11 13 15 basılacak ekrana
         sonra 1 == 1 oldugu için return yapılıyor ...çıkış
 */

//2- Klavyeden bir kelimenin, girilen bir cümlede kaç kez tekrar ettiğini bulan programı yazınız.
void kelime_ara() {
    string cumle, aranan_kelime, aktif_kelime = "";
    int kere = 0;
    cout << "Cumleyi girin : ";
    getline(cin,cumle);
    cout << "Aranmasi gereken kelimeyi girin : ";
    getline(cin, aranan_kelime);

    for (int i = 0; i < cumle.length(); i++) {
        if (cumle[i] != ' ') {
            aktif_kelime += cumle[i];
        }else {
            kere += aktif_kelime == aranan_kelime ? 1 : 0;
            aktif_kelime = "";
        }

        if (i == cumle.length() - 1) {
            kere += aktif_kelime == aranan_kelime ? 1 : 0;
            aktif_kelime = "";
        }
    }
    
    if(kere > 0)
        cout << aranan_kelime << " kelimesi cumlede " << kere << " kere bulundu" << endl;
    else
        cout << aranan_kelime << " kelimesi cumlede bulunamadi" << endl;
}

/*
3- İki boyutlu bir dizinin her satırının ve her sütununun toplamlarını ayrı ayrı hesaplayan
   ve bulduğu sonuçları ekranda görüntüleyen programı yazınız.
*/

void satir_sutun_toplayan() {
    /*  rasgele olarak seçilen matrix
        7   8   9
        5   6   6
        1   2   3
    */
    int matrix[3][3] = {{7,8,9}, {5, 6, 6}, {1, 2, 3}};
    int sutun_toplamlari[3] = {0 ,0 ,0};

    for (int i = 0; i < 3; i++) {
        int sat_say = 0;
        for (int j = 0; j < 3; j++) {
            sat_say += matrix[i][j];
            sutun_toplamlari[j] += matrix[i][j];
        }
        cout << (i + 1) << ". satir elemanlarinin toplami : " << sat_say << endl;
    }
    cout << "----------------------------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << (i + 1) << ". sutun elemanlarinin toplami : " << sutun_toplamlari[i] << endl;
    }
}

/*

4- 0’dan klavyeden girilen sayıya kadar olan sayılardan; tek olanları tek sayılar dizisine,
    çift olanları çift sayılar dizisine saklayan ve bu dizileri ayrı ayrı ekrana yazdıran
    programı yazınız

*/
void tek_cift_ayiran() {
    int limit, k=0, c=0;
    cout << "Limit sayisi girin : " << endl;
    cin >> limit;
    //Sayıyoruz kaç tek var kaç çift vvar
    for (int i = 0; i < limit; i++) {
        if (i % 2 == 0)
            c++;
        else
            k++;
    }
    // ayırma
    int* tekler = new int[k];
    int* ciftler = new int[c];
    int t2 = 0; int c2 = 0;

    for (int i = 0; i < limit; i++) {
        if (i % 2 == 0) {
            ciftler[c2] = i;
            c2++;
        }
        else
        {
            tekler[t2] = i;
            t2++;
        }

    }
    //yazdırma
    cout << "Cift sayilari" << endl;
    for (int i = 0; i < c; i++) {
        cout << ciftler[i] << endl;
    }
    cout << "Tek sayilari" << endl;
    for (int i = 0; i < k; i++) {
        cout << tekler[i] << endl;
    }
}

/*
    5- Klavyeden girilen bir metnin içindeki sesli ve sessiz harflerin sayısını bulan programı yazınız
*/
string check(char ch) {

    string sesli_harflar = "ıoiueaüöy";
    bool etisting = false;
    for (int i = 0; i < sesli_harflar.length(); i++) {
        if (sesli_harflar[i] == ch) {
            etisting = true;
            break;
        }
    }
    if (etisting) {
        return "sesli";
    }
    else {
        if (ch != ' ') {
            return "sessiz";
        }
        else {
            return "bos";
        }
    }
}

void sesli_sesiz_sayan() {
    int sesli = 0, sessiz = 0;
    string metni;
    cout << "Metnizi giriniz : ";
    getline(cin, metni);

    for (int i = 0; i < metni.length(); i++) {
        if (check(metni[i]) == "sesli")
        {
            sesli++;
        }
        else if(check(metni[i]) == "sessiz") {
            sessiz++;
        }
    }
    cout << "Sesli hafler : " << sesli << endl << "Sessiz harfler : " << sessiz << endl;
}


/*
    6- Tek boyutlu bir diziyi kendi üzerinde ters sıraya çeviren programı yazınız.

*/

void siralayan() {

    int dizi[] = { 1, 2, 3, 4, 5 };
    int yardimci;
    for (int i = 0; i <  5; i++) {
        for (int j = 0; j < 5; j++) {
            if (dizi[i] > dizi[j]) {
                yardimci = dizi[j];
                dizi[j] = dizi[i];
                dizi[i] = yardimci;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << dizi[i];
    }
    cout << endl;
}

/*
7- Katsayıları kullanıcıdan alınan 2.dereceden bir denklemin varsa köklerini bulup
    yazdıran, yoksa kök yoktur çıktısını veren programı yazınız.
*/

void deklem_coz() {
    int a, b, c = 0;
    double delta, x1, x2 = 0;

    cout << "deklemin katsayilari girin a sonra b sonra c sonra: " << endl;
    cin >> a >> b >> c;

    delta = (b * b) - 4 * (a * c);

    if (delta > 0)
    {
        x1 = (-b - sqrt(delta) ) / 4 * a;
        x2 = (-b + sqrt(delta)) / 4 * a;
        cout << "Deklemin kokleri : x1=" << x1 << " ve x2=" << x2 << endl;
    }
    else if (delta == 0) {
        x1 = -b / 2 * a;
        cout << "Deklemin kokleri esit : x1=x2=" << x1 << endl;
    }
    else {
        cout << "kok yoktur..." << endl;
    }
}


/*
8 - Sayı tahmin oyunu tasarlayınız.Kullanıcıdan 0 ile 100 arasında bir sayı tutmasını
    isteyiniz.Her defasında aralığı ikiye bölerek daraltma işlemi yapınız. Kullanıcının
    tahmini ettiği sayıyı bulmaya çalışınız.
*/

void burasi(int aralik_min, int aralik) {
    int ceker;
    int benim_tahminim = rand() % aralik + aralik_min;

    cout << "Tuttugunuz sayi : " << benim_tahminim << " ? " << endl;
    cout << "Tamhinin dogru ise 0 ginin kucuk ise -1 girin buyuk ise 1 girin : " << endl;
    cin >> ceker;
    if (ceker == 1) {
        burasi(aralik_min, benim_tahminim);
    }
    else if (ceker == -1) {
        burasi(benim_tahminim, aralik);
    }
    else {
        cout << "Tebrikler !!" << endl;
    }
}

void tahmin_oyunu() {
     cout << "0 ile 100 arasinda bir sayi tutun...." << endl << "Tuttuysaniz oyuna baslamak icin enter dugmeye basin" << endl;
     burasi(0, 100);
}


int main() {
    //kelime_ara();
    //satir_sutun_toplayan();
    //tek_cift_ayiran();
    //sesli_sesiz_sayan();
    //siralayan();
    //deklem_coz();
    //tahmin_oyunu();
}
