using System;

namespace prog2_Odev1
{
    class Program
    {
        static void Main(string[] args)
        {

            //Aşama 1: e-posta bölme işlemi

            static void epostaBolmeFonksiyonu()
            {

                string tamEpost = "" ;
                
                //doğru bir e-posta girilmesine kadar e-posta istenecek
                do
                {
                    Console.Write("E-postayı giriniz : ");
                    tamEpost = Console.ReadLine();

                } while (!tamEpost.Contains("@"));

                tamEpost = tamEpost.Trim();

                string kullanici = tamEpost.Substring(0, tamEpost.IndexOf("@"));
                string domain = tamEpost.Remove(0, tamEpost.IndexOf("@") + 1);

                Console.WriteLine("\nEmail : " + tamEpost + "\nkullanıcı : " + kullanici + "\nDomain : " + domain + "\n");

            }

            //Aşama 2: string bolme

            static void stringBolmeFonksiyonu()
            {
                Console.Write("Lutfen bir string griniz : ");
                string girilenString = Console.ReadLine().Trim();

                string kelime = "";
                Console.Write("\n");

                do
                {
                    if (!girilenString.Contains(" "))
                    {
                        kelime = girilenString;
                        girilenString = "";
                    }
                    else
                    {
                        kelime = girilenString.Substring(0, girilenString.IndexOf(" "));
                        girilenString = girilenString.Remove(0, girilenString.IndexOf(" ") + 1);
                    }
                    
                    Console.WriteLine("Dönüs : " + kelime);

                } while (girilenString.Contains(" ") || girilenString.Length > 0);
            }

            //ÇALIŞTIRILMASI

            Console.WriteLine("************************  1.KISIM  ************************\n");

            epostaBolmeFonksiyonu();

            Console.WriteLine("************************  2.KISIM  ***********************\n");

            stringBolmeFonksiyonu();
        }
    }
}
