using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _191307093_judy_ndotoni_VizeProjesi
{
    class Ogrenci
    {

        //Sınıf üye elemanlarin tanımı
        #region Sınıf üye değişkenleri
        string ad;
        string soyad;
        string bolum;
        string tcno;
        char cinsiyet;
        double basariNotu;

        string[] AlinanDersler;
        double[] dersNotlari;
        #endregion

        /*-------------- Sınıf metotlarının tanımı -------------------*/

        #region Sınıf kurucu metodu ve aşiri yüklenmeleri (Kopya kurucusu dahil)

        //Sınıf parametresiz kurucusu 
        public Ogrenci()
        {
            ad = "tanımsız";
            soyad = "tanımsız";
            bolum = "tanımsız";
            tcno = "tanımsız";
            cinsiyet = '-';
            basariNotu = 0.0;

            AlinanDersler = new string[]{ "tanımsız", "tanımsız", "tanımsız" };
            dersNotlari = new double[] {0.0, 0.0, 0.0};
        }

        //Sınıf 1 parametreli kurucusu 
        public Ogrenci(string tcNumerası):this() 
        {
            tcno = tcNumerası;
            //tcNo vatandişin bilgileri taşıdığı için  tek parametreli kurucuda uygundur.
            //this() ile parametriz kurucu çaliştirilarak diğer üye elemanlarin ilk atama yapılır 
        }

        //Sınıf 2 parametreli kurucusu
        public Ogrenci(string tcNumerası, string ogrenciBolumu):this()
        {
            tcno = tcNumerası;
            bolum = ogrenciBolumu;
            //this() ile parametriz kurucu çaliştirilarak diğer üye elemanlarin ilk atama yapılır 
        }

        //Sınıf kopya kurucusu
        public Ogrenci(Ogrenci bir_Ogrenci_nesnesi)
        {
            ad = bir_Ogrenci_nesnesi.ad;
            soyad = bir_Ogrenci_nesnesi.soyad;
            bolum = bir_Ogrenci_nesnesi.bolum;
            tcno = bir_Ogrenci_nesnesi.tcno;
            cinsiyet = bir_Ogrenci_nesnesi.cinsiyet;
            basariNotu = bir_Ogrenci_nesnesi.basariNotu;

            AlinanDersler = bir_Ogrenci_nesnesi.AlinanDersler;
            dersNotlari = bir_Ogrenci_nesnesi.dersNotlari;
        }
        #endregion

        //Sınıf içinde, ders notlarını kullanıp başarı notunu hesaplayan bir metot
        public double basariNotuHesaplama()
        {
            double NotToplama = 0.0;
            double _basariNot = 0.0;
            for (int i = 0; i < 3; i++)
            {
                NotToplama += this.dersNotlari[i];
            }

            _basariNot = NotToplama / 3; //başari notun 100'de orantılı
            _basariNot /= 25;  //başari notun 4'de orantılı

            this.basariNotu = _basariNot;
            return _basariNot;
        }

        //Öğrenci bilgilerini(tüm üye değerlere atama yapılacak) dışardan alan
        public void ogrenciBilgileri(string _ad, string _soyad, string _bolum, string _tcno, char _cinsiyet, string[] _AlinanDersler, double[] _dersNotlari)
        {
            this.ad = _ad;
            this.soyad = _soyad;
            this.bolum = _bolum;
            this.tcno = _tcno;
            this.cinsiyet = _cinsiyet;

            this.AlinanDersler = _AlinanDersler;
            this.dersNotlari =_dersNotlari;
            this.basariNotuHesaplama();
        }

        //Öğrenci yazdiran metodu
        public void ogrenciYaz()
        {
            Console.WriteLine("*************  Öğrenci Bilgileri  ************");
            Console.WriteLine("Ad : " + this.ad);
            Console.WriteLine("SoyAd : " + this.soyad);
            Console.WriteLine("Cinsiyet : " + this.cinsiyet);
            Console.WriteLine("TC numera : " + this.tcno);
            Console.WriteLine("Bölüm : " + this.bolum);
            Console.WriteLine("\nPuan durumu : ");

            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("\t" + this.AlinanDersler[i] + " : " + this.dersNotlari[i] + ";");
            }

            Console.WriteLine("\nBaşari Notu : " + this.basariNotu + "\n");

        }
        //Yikici metot
        ~Ogrenci()
        {
            Console.WriteLine("yıkıcı çalıştı...");
        }

        static void Main(string[] args)
        {
            //parametresiz kurucu ile türetilmiş bir nesne
            Ogrenci judy = new Ogrenci();
            judy.ogrenciYaz();

            //daha sonra ogrenci Bilgi atama metodu çaliştirildiğinda
            string[] judyDersleri = { "Algoritma", "Programlama", "Pro. Lab" };
            double[] judyNotlari = { 94.5, 96, 100 };
            judy.ogrenciBilgileri("Judy Ndotoni", "Nkwama", "Bilişim Sistemleri Mühendisliği", "131307093", 'E', judyDersleri, judyNotlari);
            judy.ogrenciYaz();


            // 1 parametreli kurucu türetilmiş bir nesne
            Ogrenci mehmet = new Ogrenci("994953449856");
            mehmet.ogrenciYaz();


            // 2 parametreli kurucu türetilmiş bir nesne
            Ogrenci asli = new Ogrenci("9985445354556", "Toplumsal Ekonomi");
            asli.ogrenciYaz();
        }
    }
}
