/*
 
 ------- 191307093 JUDY NDOTONI NKWAMA -------------
 
 */

#include <iostream>
using namespace std;

struct Dugum
{
    int data;
    struct Dugum* sol, * sag;
    //En basta solda BF=0 ve sagda BF=0; 0 - 0 = 0; -1<=0<=1
    string dengelikDurum = "Agac dengelidir";
};

typedef struct Dugum avlAgaci;

avlAgaci* new_node(int data)
{
    avlAgaci* p = new avlAgaci;
    p->data = data;
    p->sol = NULL;
    p->sag = NULL;
    p->dengelikDurum = true;
    return p;
}

int yukseklik_temp(Dugum* dugum){
    if(dugum == NULL){
        return -1;
    }else{
        int solYuseklik = yukseklik_temp(dugum->sol);
        int sagYukseklik = yukseklik_temp(dugum->sag);
        return ( max(solYuseklik, sagYukseklik) + 1 );
    }
}

int yukseklik(Dugum* dugum){
    return (yukseklik_temp(dugum) + 1);
}

int b_faktor(Dugum * dugum) {
   int solYuseklik = yukseklik(dugum->sol);
   int sagYukseklik = yukseklik(dugum->sag);
   int b_faktor = solYuseklik - sagYukseklik;
   return b_faktor;
}

avlAgaci* sag_dondur(avlAgaci *parent) {
   avlAgaci *t;
   t = parent->sag;
   parent->sag = t->sol;
   t->sol = parent;
   cout<<"Sag-Sag dondurme";
   return t;
}

avlAgaci* sol_dondur(avlAgaci *parent) {
   avlAgaci *t;
   t = parent->sol;
   parent->sol = t->sag;
   t->sag = parent;
   cout<<"Sol-sol Rotation";
   return t;
}

avlAgaci* sol_sag_dondur(avlAgaci *parent) {
   avlAgaci *t;
   t = parent->sol;
   parent->sol = sag_dondur(t);
   return sol_dondur(parent);
}
avlAgaci* sag_sol_dondur(avlAgaci *parent) {
   avlAgaci *t;
   t = parent->sag;
   parent->sag = sol_dondur(t);
   return sag_dondur(parent);
}

avlAgaci* dendele(avlAgaci *t) {
   int bal_factor = b_faktor(t);
   if (bal_factor > 1) {
      if (b_faktor(t->sol) > 0)
         t = sol_dondur(t);
      else
         t = sol_sag_dondur(t);
   } else if (bal_factor < -1) {
      if (b_faktor(t->sag) > 0)
         t = sag_sol_dondur(t);
      else
         t = sag_dondur(t);
   }
    
    if( abs(yukseklik(t->sol) - yukseklik(t->sag)) > 1 ){
        t->dengelikDurum = "Agac dengesizdir";
    }else{
        t->dengelikDurum = "Agac dengelidir";
    }
    
   return t;
}


avlAgaci* yeniDugum(avlAgaci* root, int data)
{
    if (root != NULL) //ağaç boş değilse
    {
        if (data < root->data)
            root->sol = yeniDugum(root->sol, data);
        else
            root->sag = yeniDugum(root->sag, data);

    }
    else{ //boşsa
        root = new_node(data);
    }
    
    if( abs(yukseklik(root->sol) - yukseklik(root->sag)) > 1 ){
        root->dengelikDurum = "Agac dengesizdir";
    }else{
        root->dengelikDurum = "Agac dengelidir";
    }
    return root;
}

void preorder(avlAgaci* root)//root(kök)-sol-sağ
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->sol);
        preorder(root->sag);
    }
}

//inoder
void inorder(avlAgaci* root)//sol-root(kök)-sağ
{
    if (root != NULL)
    {
        preorder(root->sol);
        cout << root->data << " ";
        preorder(root->sag);
    }
}


int main()
{
    
    setlocale(LC_ALL, "Turkish");//türkçe karakter
    avlAgaci* root = NULL;
    int sayi;
    root = yeniDugum(root, 5);
    yeniDugum(root, 2);
    yeniDugum(root, 1);
    yeniDugum(root, 4);
    yeniDugum(root, 3);
    yeniDugum(root, 7);
    yeniDugum(root, 6);
    yeniDugum(root, 9);
    yeniDugum(root, 16);
    
    cout << "Agacin ilk hali" << endl;
    inorder(root);
    
    cout << endl;
    cout << "sol Yuksekligi : " << yukseklik(root->sol) << endl;
    cout << "sag Yuksekligi : "<< yukseklik(root->sag) << endl;
    cout << "DF : "<< b_faktor(root) << endl;
    cout << "Dengelik : "<< root->dengelikDurum << endl<< endl;
    
    cout << "______ 15 ekleme ______" << endl << endl;
    yeniDugum(root, 15);
    inorder(root); cout << endl;
    
    cout << "sol Yuksekligi : " << yukseklik(root->sol) << endl;
    cout << "sag Yuksekligi : "<< yukseklik(root->sag) << endl;
    cout << "DF : "<< b_faktor(root) << endl;
    cout << "Dengelik : "<< root->dengelikDurum << endl;
    
    
    cout << endl <<  "______ Agac hala Dengeli. Dengesizlemek icin 14 ekleniyor ______" << endl << endl;
    cout << "______ 14 ekleme ______" << endl << endl;
    yeniDugum(root, 14);
    inorder(root); cout << endl;
    
    cout << "sol  Yuksekligi : " << yukseklik(root->sol) << endl;
    cout << "sag Yuksekligi : "<< yukseklik(root->sag) << endl;
    cout << "DF : "<< b_faktor(root) << endl;
    cout << "Dengelik : "<< root->dengelikDurum << endl << endl;
    
    cout << "______ Dengeleme islemi ______" << endl << endl;
    root = dendele(root);
    cout << endl;
    
    inorder(root); cout << endl;
    
    cout << "sol Yuksekligi : " << yukseklik(root->sol) << endl;
    cout << "sag Yuksekligi : "<< yukseklik(root->sag) << endl;
    cout << "DF : "<< b_faktor(root) << endl;
    cout << "Dengelik : "<< root->dengelikDurum << endl;
    
    
    return 0;
}
