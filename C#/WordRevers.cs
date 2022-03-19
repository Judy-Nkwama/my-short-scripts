using System;

namespace kelimeyiTerstenYazdıran
{
    
    public static class Class2
    {
        public static string terstenVeren(string a)
        {
            string[] diziKelime = new string[a.Length];
            string terstenKelime = "";
            for (int i = (a.Length -1); i>=0 ; i--)
            {
                terstenKelime += a[i];
            }
            return terstenKelime;
        }
        
        public static void CalculePourcentage()
        {
            Console.WriteLine("Entrez le nombre des cours");
            byte derslerSayisi = Convert.ToByte(Console.ReadLine());

            
            byte[] notes = new byte[derslerSayisi];
            string[] metieres = new string[derslerSayisi];
            byte[] ponderation = new byte[derslerSayisi];

            float pour = 0;
            int pondTotale = 0;
            string design = "";

            for (int i = 0; i < derslerSayisi; i++)
            {
                Console.WriteLine("Veillez entrer le titre du Cours Numero  " + (i+1));
                metieres[i] = Console.ReadLine();
                Console.WriteLine("Veillez entrer la ponderation pour : " + metieres[i]);
                ponderation[i] = Convert.ToByte(Console.ReadLine());
                
                Console.WriteLine("Veillez entrer la note obtenu en " + metieres[i]);
                notes[i] = Convert.ToByte(Console.ReadLine());
            }

            Console.Clear();
            Console.WriteLine("\n---------------------- Bulletin de l'etudiant --------------------\n");

            Console.WriteLine("\tNo Matiere         \t Pond. \t Max \t Obtenu");
            for (int i = 0; i < derslerSayisi; i++)
            {
                design = "";
                for (int j = (15 - metieres[i].Length); j > 0; j--)
                {
                    design += " ";
                }
                Console.WriteLine("\t" + (i+1) + ". " + metieres[i] + design + " \t " + ponderation[i] + " \t 100 \t " + notes[i]);
                pour += notes[i] * ponderation[i];
                pondTotale += ponderation[i] * 100;
            }
            pour = (pour / pondTotale) * 100;

            Console.WriteLine("\n--------------------------- Resultat Final -----------------------\n");

            Console.WriteLine("Pourcentage obtenu : " + (int)pour + "%");
            Console.Write("Mension : ");

            if (pour >= 80) Console.Write("Grande Distinction ");
            else if (pour >= 70) Console.Write("Distinction ");
            else if (pour >= 70) Console.Write("Distinction ");
            else if (pour >= 50) Console.Write("Satisfaction ");
            else if (pour < 50) Console.Write("Echec ");

            Console.WriteLine("\n\n");
        }

        public static void plusGros_plusPetit()
        {
            sbyte girilen = new int();
            bool devam = true;
            int a = 0;
            while (devam)//jouer-rejouer
            {
                girilen = -1;
                a = 0;
                sbyte tahmin = (sbyte)(new Random()).Next(0, 101);
                Console.WriteLine("Tahmin edin");
                while (true)//deviner-a nouveau
                {
                    if (!(sbyte.TryParse(Console.ReadLine(), out girilen) && tahmin < 101)) Console.WriteLine("0 ile 100 arasında olan bir tam sayı giriniz lütfen");
                    else if (tahmin != girilen)
                    {
                        a++;
                        if (girilen > tahmin) Console.WriteLine("Daha büyüktür!. Yeniden tahmin edin.");
                        else if (girilen < tahmin) Console.WriteLine("Daha küçüktür!. Yeniden tahmin edin.");
                    }
                    else
                    {
                        Console.WriteLine("Aferin!! " + a + ". girişte buldunuz\nOyuna devam etmek için d tuşuna basın!");
                        devam = ((Console.ReadKey(true)).Key == ConsoleKey.D) ? true : false;
                        break;
                    }
                }
            }
        }
        public static void Odev9()
        {
            Console.WriteLine("Üç veya Dört basamaklı bir sayıyı girin lütfen");
            string girilenSayi = Console.ReadLine();
            int len = girilenSayi.Length;
            if (!int.TryParse(girilenSayi, out int sayi) || (len != 3 && len != 4)) Console.WriteLine("Geçersiz sayı girdiniz.");
            else if (len == 3)
            {
                int kareliToplam = 0;
                for (int i = 0; i < len; i++)
                {
                    kareliToplam += (int)Math.Pow(Convert.ToInt32(girilenSayi.Substring(i, 1)), 2);
                }
                Console.WriteLine(sayi + " sayısının basamak kareleri toplamı: " + kareliToplam);
            }
            else
            {
                if (sayi % 4 == 0) Console.WriteLine(sayi + " sayısı 4 ile tam bölünür.");
                else Console.WriteLine(sayi + " sayısı 4 ile tam bölünmez.");
            }
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            /*Console.WriteLine("Tersten yazdırmayı istediğiniz kelimeyi girin");
            Console.WriteLine(Class2.terstenVeren(Console.ReadLine()));*/

            Class2.CalculePourcentage();
        }
    }
}
