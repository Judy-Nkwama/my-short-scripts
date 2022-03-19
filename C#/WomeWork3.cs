using System;

namespace sinav1
{
    class Program
    {   
        
        /*int faktoryel(int a) 
        {
            if (a == 0) return 0;
            int thefak = 1;
            while (a >= 1)
            {
                thefak *= a--;
            }
            return thefak;
        }*/
        static void Main(string[] args)
        {
            //Örnek1: Basamakları ayıran programı
            {
                /*int intvalue = 0;
                Console.WriteLine("Bir tam sayı giriniz lütfen");
                while (!int.TryParse(Console.ReadLine(), out intvalue))
                {
                    Console.WriteLine("Girdiğiniz sayı yanlış!!. Tekrardan bir tam sayı giriniz lütfen");
                }
                int basamaklik = 1;
                int basamaDeger = 0;
                while (intvalue > 0)
                {
                    basamaDeger = intvalue % 10;
                    intvalue -= basamaDeger;
                    intvalue /= 10;
                    Console.WriteLine(basamaklik + " basamaklı değer : " + basamaDeger);
                    basamaklik *= 10;
                }*/
            }

            //Örnek2: 10 sayılarından pozitiflar ve negatiflar belirten programı
            {
               /*double[] dizi = new double[10];
               for (int i = 0; i < 10; ++i)
               {
                   Console.WriteLine("Dizinin " + (i+1) + ". elemanı giriniz lütfen" );
                   while (!(double.TryParse(Console.ReadLine(), out dizi[i])))
                   {
                       Console.WriteLine("Girdiğiniz sayı geçersiz. Lütfen yeniden giriniz.");
                   }
               }
               for (int i = 0; i < 10; ++i)
               {
                   if (dizi[i] >= 0) Console.WriteLine((i + 1) + "/ " + dizi[i] + " pozitiftir");
                   else Console.WriteLine((i + 1) + "/ " + dizi[i] + " negatiftir");
               }*/  
            }

            //Örnek3: faktoryel programı
            {
                /*Console.WriteLine("fAKTORYELİ BULUNMASI GEREKEN SAYIYI GİRİN");
                int sayi = 0;
                while (!(int.TryParse(Console.ReadLine(), out sayi) && sayi >= 0))
                {
                    Console.WriteLine("Yanlış!! Yediden giriniz.");
                }
                Program a = new Program();
                Console.WriteLine(sayi + " sayısının faktorieli " + a.faktoryel(sayi) + " dir");*/
            }

            //Örnek4: fibonacci series
            {
                /*Console.WriteLine("Serinin ilk sayıyı gininiz");
                decimal sayi = 0;
                decimal maxsayi = 0;

                while (!(decimal.TryParse(Console.ReadLine(), out sayi)))
                {
                    Console.WriteLine("Yanliş girdi. yeniden giriniz");
                }

                Console.WriteLine("Maximum değeri giriniz.");
                while (!(decimal.TryParse(Console.ReadLine(), out maxsayi)))
                {
                    Console.WriteLine("Yanliş girdi. yeniden giriniz");
                }
                decimal last1 = sayi;
                decimal last2 = 0;

                Console.Write(sayi + " ");
                while (last1 + last2 <= maxsayi)
                {
                    sayi = last1 + last2;
                    Console.Write(sayi + " ");
                    last2 = last1;
                    last1 = sayi;
                }*/
            }

            //sinavin sayi, toplam, for, a, b sorusu
            /*{
                int i, toplam, sayac, a, b;
                toplam = 0; sayac = 0;
                Console.WriteLine("Başlangıç");
                a = Convert.ToInt16(Console.ReadLine());
                Console.WriteLine("Bitiş");
                b = Convert.ToInt16(Console.ReadLine());

                for (i=1; i<7; i++)
                {
                    if (i % 2 == 1)
                    {
                        toplam = toplam + i;
                        if (sayac == 4) break;
                        sayac++;
                        Console.WriteLine("indis:" + i);
                    }
                }
                Console.WriteLine(sayac + "tane sayı toplam : " + toplam);
            }*/

            //Sinavin a++; a++; a++%2 sorusu
            {
                int a = 100;
                Console.WriteLine((++a));
                Console.WriteLine(a++);
                Console.WriteLine((a++%2));
            }

            //sinavin yüzlen ayrıran sorusu
            {
                /*int sayi = 555555;
                Console.WriteLine(sayi % 100);*/
            }
        }
    }
}
