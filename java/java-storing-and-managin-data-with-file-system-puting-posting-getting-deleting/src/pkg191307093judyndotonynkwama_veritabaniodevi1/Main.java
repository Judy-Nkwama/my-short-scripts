package pkg191307093judyndotonynkwama_veritabaniodevi1;
//Dosya ile ilgi importlar
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

//Diğer importlar
import java.util.Scanner;
/**
 *
 * @author JUDY NDOTONI NKWAMA
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static void ekranaYaz(String[][] tablo){
        //Bu fonksiyon parametre olarak bir tablo alarak consola bu tabloyu tablo şeklinde yazdırır.
        //Sıfır indexteki eleman, tablo başlığı olarak yazılır
        
        //Tablo alanlari yazdirma islemi
        
        int tablo_genisligi = 0; String line = "";
        
        int[] sutunlerin_genisleri = {0,0,0,0,0,0,0,0};
        for(int ind = 0;  ind < tablo.length ; ind++ ){

            int sutun_gen = 0;
            for(int i = 0; i < tablo.length; i++){
                for(int j = 0; j < 8; j++){
                    if(sutunlerin_genisleri[j] < tablo[i][j].length()){
                        sutunlerin_genisleri[j] = tablo[i][j].length();
                    }
                }
            }
            
            line = "+";
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < sutunlerin_genisleri[i]; j++){
                    line += "-";
                }
            }
            
            line += "----------------------------+";
        }
        
        // Kayitlari yazilmasi
        
        String kayitlar = "", kayit = "";
        for(int ind = 0;  ind < tablo.length ; ind++ ){
            
            for(int i = 0; i < tablo[ind].length; i++){
                
                if(ind == 0){
                    kayit = (( i == 0 )) ? "| ID   " + tablo[ind][i] : "| " + tablo[ind][i];
                }else{
                    kayit = (( i == 0 )) ? "| " + ind + "    " + tablo[ind][i] : "| " + tablo[ind][i];
                }
                
                int completion;
                /*if(ind == 0){
                    completion = ((sutunlerin_genisleri[i] + 1) - tablo[ind][i].length());
                }else{
                    completion = ((sutunlerin_genisleri[i] + (String.valueOf(i).length() - 1)) - tablo[ind][i].length());
                }*/
                completion = ((sutunlerin_genisleri[i] + (String.valueOf(i).length() - 1)) - tablo[ind][i].length());
                for(int j = 0; j < completion  ; j++){
                    kayit += " ";
                }
                //Kayit 
                kayitlar += i == tablo[ind].length - 1 ? kayit + " |" : kayit + " ";
                if(i == (tablo[ind].length - 1)){ // Tablonun son elemenı olmadığı taktirde break line yapıyoruz
                   kayitlar += "\n";
                    if( ind == 0 ){ // Balıktan sonra bir çizgi çiziyoruz.
                        kayitlar += line + "\n";
                    }
                }
            }
        }
        System.out.println(line + "\n" + kayitlar + line);
    }
    
    static String kayitlari_dosyadan_al(File veri_dosyasi){
  
        FileReader veri_okuyucu;
        String simdiki_veri = ""; 
        
        try{  
            veri_okuyucu = new FileReader(veri_dosyasi);
            //Kaybolmamasi için ilk olarak dosyada buluna virileri okuyup tutacağız.
            int bir_characker = 0;
            while((bir_characker = veri_okuyucu.read()) != -1 ){// okunmamış karakterlr var olduğu surece
                simdiki_veri += (char)bir_characker;
            }
            veri_okuyucu.close(); 
        }catch (FileNotFoundException e) {
            e.printStackTrace();
        }catch (IOException e) {
            e.printStackTrace();
        }
        
        return simdiki_veri;
        
    }

    static void kayitlari_dosyaya_yaz(File veri_dosyasi, String yazilacak){
        FileWriter veri_yazici;
        try{
            //Dosyaya yeni kayit ekleme işlem
            veri_yazici = new FileWriter(veri_dosyasi);
            veri_yazici.write(yazilacak);
            veri_yazici.close();
           
        }catch (FileNotFoundException e) {
            e.printStackTrace();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    static void kayit_eklme(File veri_dosyasi){
        //burade verilerin girildiği sıra önemlidir
        String[] alanlar = {
            "adı", "soyadı", "öğrenci numarası", "bolumu", "cinsiyeti", 
            "doğum yeri", "yaşı", "telefon numarası"
        };
    
        String girilen = "", yeniKayit = "";
        Scanner mesajci = new Scanner(System.in);
        for (int i = 0; i < alanlar.length ; i++){
            do{
                System.out.println("Öğrencinin " + alanlar[i] + " giriniz. (Türk karakterleri, virgülü içeremez, boş olamaz) : ");
                girilen = mesajci.nextLine();
            }while(girilen.contains(",") || girilen.length() == 0);
            yeniKayit += girilen;
            if( i != alanlar.length - 1 ){ // son eleman değilse
                yeniKayit += ", ";
            }
            girilen = "";
        }
        String eksiKayitlar = kayitlari_dosyadan_al(veri_dosyasi);
        kayitlari_dosyaya_yaz(veri_dosyasi, eksiKayitlar + "\n" + yeniKayit);
        
        System.out.println("\n###-- Dosya'ya bir kayit basarili bir sekilde eklendi! ---###\n");
    }
    
    static String[][] kayit_listeleme(File veri_dosyasi){
        
        String dosyaIcerigi = kayitlari_dosyadan_al(veri_dosyasi);
        String[] satirlarTablosu = dosyaIcerigi.split("\n");
        String[][] kayitlartablosu = new String [satirlarTablosu.length][8];
        
        for(int i = 0; i < kayitlartablosu.length ; i++){
            kayitlartablosu[i] = satirlarTablosu[i].split(",");
        }
        return kayitlartablosu; 
    }
    
    static void kayit_Arama(File veri_dosyasi){
        Scanner okuyucu = new Scanner(System.in);
        String[][] kayitlar = kayit_listeleme(veri_dosyasi);
        String[] alanlar = {
            "adı", "soyadı", "öğrenci numarası", "bolumu", "cinsiyeti", 
            "doğum yeri", "yaşı", "telefon numarası"
        };
        
        for(int i = 0 ; i < alanlar.length; i++){
            System.out.println("Öğrenci " + alanlar[i].toUpperCase() + " ile aramak için : " + i);
        }
        
        boolean invalid = true;
        int arama_alani; 
        String giriris;
        
        do{
            arama_alani = -1 ;
            System.out.print("Arama alani giriniz : ");
            giriris = okuyucu.next();
            
            try{
                arama_alani = Integer.parseInt(giriris);
                System.out.println("Arama " + alanlar[arama_alani] + " ile yapiliyor...");
                invalid = false;
            }catch(Exception e){
                System.out.println("Sadece 0,1,2,3,4,5,6,7 tam sayilari girebilisiniz");
                invalid = true;
            }
        }while(invalid);
        
        System.out.println("Aranmasi gereken " + alanlar[arama_alani].toUpperCase() + " giriniz : ");
        String anahtar = okuyucu.next();
        int bulunanSayisi = 0;
        
        //System.out.println(anahtar);
                
        for(int i = 0; i<kayitlar.length; i++){
            if((kayitlar[i][arama_alani].trim().toLowerCase()).equals(anahtar.trim().toLowerCase())){
                bulunanSayisi++;
            }
        }
        
        String[][] bulunan = new String[bulunanSayisi + 1][8];
        String[]  balik = {"Adı", "Soyadı", "Öğrenci numarası", "Bolumu", "Cinsiyeti","Doğum yeri", "Yaşı", "Telefon numarası"};
        bulunan[0] = balik;
        
        int index = 0;
        for(int i = 0; i<kayitlar.length; i++){
            if((kayitlar[i][arama_alani].trim().toLowerCase()).equals(anahtar.trim().toLowerCase())){
                bulunan[index + 1] = kayitlar[i];
                index++;
            }
        }
        if(bulunan.length > 1){
            ekranaYaz(bulunan);
        }else{
            System.out.println("\n###-- hiç bir sonunca ulasilamadi --##\n");
        }
    }
    
    static void kayit_Duzenle(File veri_dosyasi){
        
        Scanner okuyucu = new Scanner(System.in);
        String[][] kayitlar = kayit_listeleme(veri_dosyasi);
        String[] alanlar = {
            "adı", "soyadı", "öğrenci numarası", "bolumu", "cinsiyeti", 
            "doğum yeri", "yaşı", "telefon numarası"
        };
        
        for(int i = 0 ; i < alanlar.length; i++){
            System.out.println("Öğrencinin " + alanlar[i].toUpperCase() + " duzeltmek için : " + i);
        }
        
        boolean invalid = true;
        int duzeltme_alani; 
        String giriris;
        
        do{
            duzeltme_alani = -1 ;
            System.out.print("Düzeltmek istediginiz alani giriniz : ");
            giriris = okuyucu.next();
            
            try{
                duzeltme_alani = Integer.parseInt(giriris);
                invalid = false;
            }catch(Exception e){
                System.out.println("Sadece 0,1,2,3,4,5,6,7 tam sayilari girebilisiniz");
                invalid = true;
            }
        }while(invalid);
        
        int id = -1; String[] tab;
        do{
            try{
                System.out.println(alanlar[duzeltme_alani] + " duzeltilecek Ögrencinin ID'si giriniz : ");
                id = okuyucu.nextInt();
                tab = kayitlar[id];
            }catch(Exception e){
                System.out.println("Var olan bir ID girin, tablo listeyip vemcut IDlari gorebiliyorsunuz");
                id = -1;
            }
            if(id == 0){
                System.out.println("Var olan bir ID girin, tablo listeyip vemcut IDlari gorebiliyorsunuz");
                id = -1;
            }
        }while(id == -1);
        
        
        Scanner mesajci = new Scanner(System.in);
        System.out.println("Yeni " + alanlar[duzeltme_alani] +  " giriniz : ");
        String yeni_degeri = mesajci.nextLine();
        
        kayitlar[id][duzeltme_alani] = " " + yeni_degeri;
        
        
        String str = "";
        for(int i = 0 ; i < kayitlar.length; i++){
            for(int j = 0 ; j < kayitlar[i].length; j++){
                str += kayitlar[i][j] + ",";
                if(j == (kayitlar[i].length - 1)){
                    str += "\n";
                }
            }
        }
        
        kayitlari_dosyaya_yaz(veri_dosyasi, str);
        ekranaYaz(kayit_listeleme(veri_dosyasi));
        
    }
    
    public static void main(String[] args) {
        Scanner okuyucu = new Scanner(System.in);
        File veri_dosyasi = new File("ogrenciler.dat");

        //Dosya yoksa oluşturulacak
        if(!veri_dosyasi.exists()){
            try{
                veri_dosyasi.createNewFile();
            }catch(IOException e){
                e.printStackTrace();
            }
        }
        
        String[] secenekler = {"Kayıt Eklemek", "Kayıtları Listelemek", "Kayıt Aramak", "Kayıt Düzenlemek", "Çıkış yapmak"};
        int secenek = -1; 
        
        do{
            for(int i = 0; i < secenekler.length; i++){
                System.out.println(secenekler[i] + " için " + i + " girin");
            }
            
            System.out.println("Seceneginizi girin : ");
            secenek = okuyucu.nextInt();
            
            if(secenek == 0){
                kayit_eklme(veri_dosyasi);
            }else if(secenek == 1){
                ekranaYaz(kayit_listeleme(veri_dosyasi));
            }else if(secenek == 2){
                kayit_Arama(veri_dosyasi);
            }else if(secenek == 3){
                kayit_Duzenle(veri_dosyasi);
            }else if(secenek == 4){
                secenek = 10;//Çikis
            }
            
        }while((secenek >= 0 &&  secenek < 4));

    }
}