#include <iostream>
using namespace std;

struct Dugum
{
    int data;
    struct Dugum* sol, * sag;
};
typedef struct Dugum ikiliAramaAgaci;

ikiliAramaAgaci* yeni_dugum(int data)
{
    ikiliAramaAgaci* p = new  ikiliAramaAgaci;
    p->data = data;
    p->sol = NULL;
    p->sag = NULL;
    return p;
}

ikiliAramaAgaci* ekle(ikiliAramaAgaci* root, int data)
{
    if (root != NULL) //ağaç boş değilse
    {
        if (data < root->data)
            root->sol = ekle(root->sol, data);
        else
            root->sag = ekle(root->sag, data);

    }
    else //boşsa
        root = yeni_dugum(data);
    return root;
}

void preorder(ikiliAramaAgaci* root)//root(kök)-sol-sağ
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->sol);
        preorder(root->sag);
    
    }
}

//inoder
void inorder(ikiliAramaAgaci* root)//sol-root(kök)-sağ
{
    if (root != NULL)
    {
        preorder(root->sol);
        cout << root->data << " ";
        preorder(root->sag);
    }
}

//postorder
void postorder(ikiliAramaAgaci* root)// sol-sağ-root(kök)
{

    if (root != NULL)
    {
        preorder(root->sol);
        preorder(root->sag);
        cout << root->data << " ";
    }
}

Dugum*  enKucukBul(Dugum * root){
    if(root->sol==NULL){
        return root;
    }else{
        Dugum* tem = enKucukBul(root->sol);
        return tem;
    }
}


ikiliAramaAgaci* sil(ikiliAramaAgaci* root, int x)
//ağacın kökünün bilinmesi gerekir (kökü root pointer ı gösterir) ve parametre olarak silinecek olan x değerini alalım
{
    
    if(root == NULL){
        return root;
    }else if( x < root->data ){
        sil(root->sol, x);
    }else if( x > root->data ){
        sil(root->sag, x);
    }else{
        //silme islemi
        if(root->sag== NULL && root->sol == NULL){//durum 1: cocugu yoksa
            delete root;
            root = NULL;
        }else if(root->sol == NULL){//1. durum. Sadeci 1 cocugu var
            Dugum *temp = root;
            root = root->sag;
            delete temp;
        }else if(root->sag == NULL){
            Dugum *temp = root;
            root = root->sol;
            delete temp;
        }else{//durum 3 : 2 cocugu varsa
            Dugum * enKucukEleman = enKucukBul(root->sag);
            root->data = enKucukEleman->data;
            root->sag = sil(root->sag, enKucukEleman->data);
        }
    }
    
    return root;
}

int main()
{
    //“50, 28, 46, 80, 47, 96, 14, 10, 68, 20, 34, 71, 61, 82, 98”
    setlocale(LC_ALL, "Turkish");//türkçe karakter
    ikiliAramaAgaci* root = NULL;
    int sayi;
    root = ekle(root, 50);
    ekle(root, 28);
    ekle(root, 46);
    ekle(root, 80);
    ekle(root, 47);
    ekle(root, 96);
    ekle(root, 14);
    ekle(root, 10);
    ekle(root, 68);
    ekle(root, 20);
    ekle(root, 34);
    ekle(root, 71);
    ekle(root, 61);
    ekle(root, 82);
    ekle(root, 98);
    
    
    cout <<endl<< "İnşa edilen ağacın preorder dizilimi: " << endl;
    preorder(root);
    
    cout <<endl<< "İnşa edilen ağacın inorder dizilimi: " << endl;
    inorder(root);
    
    cout <<endl<< "İnşa edilen ağacın postorder dizilimi: " << endl;
    postorder(root);
    
    cout << endl << endl <<"-----------------------------------------------" << endl;
    cout <<"           68 elemanını silinmesi....        ";
    sil(root, 68);
    cout << endl <<"-----------------------------------------------" << endl;
    

    cout <<endl<< "68 elemanını sildikten sonraki preorder dizilimi : " << endl;
    preorder(root);
    
    cout <<endl<< "68 elemanını sildikten sonraki inorder dizilimi : " << endl;
    inorder(root);
    
    cout <<endl<< "68 elemanını sildikten sonraki postorder dizilimi: " << endl;
    postorder(root);
    
    cout <<endl<<endl;
    return 0;
}
