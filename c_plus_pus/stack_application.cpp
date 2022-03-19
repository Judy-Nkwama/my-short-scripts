
/*      191307093 JUDY NDOTONI NKWAMA     */

#include <iostream>
using namespace std;

class Stack{
    
    //Yiginin uzunlugu 4 olarak ayarliyoruz
    int myArray[4];
    int stackTop = -1;
    int* dolastirici;
    
public:
    
    // Temel Stack metotlari
    
    //Yiginin en tepedeki elemani gosteren
    void top (){
        if(stackTop == -1) cout << "yigin bos su an" << endl;
        else cout << myArray[stackTop] << endl;
    }
    //Yiginin b0s olup olamadigini bakan
    bool stackIsEmpty(){
        if(stackTop == -1) return true;
        else return false;
    }
    
    //Yiginin dolu olup olmadigini bakan
    bool stackIsFull(){
        if(stackTop == 3) return true;
        else return false;
    }
    
    //Yigina eleman ekleyen
    void push(){
        if(stackIsFull()){
            cout << "yigin doludur. Su an bir eleman daha ekeleyemezsiniz." << endl;
        }else{
            int n;
            cout << "Yigina eklemek istediginiz eleman girin (tam sayi). Ekleme islemi sonlandirmak icin \"*\" girin:" << endl;
            cin >> n;
            if(n == '*'){
                cout << "Ekleme islemi sonlandirmissiniz" << n << endl;
            }else{
                stackTop++;
                myArray[stackTop] = n;
                cout << "Yigina yeni eklenmis eleman : " << n << endl;
            }
        }
    }
    //Yigindan eleman cikaran
    void pop(){
        if(stackIsEmpty()){
            cout << "Yigin bos su an. Cikartilacak bir sey yok" << endl;
        }else{
            cout << "Cikarilan eleman : "; top();
            stackTop--;
        }
    }
    //Yiginin elemani gosteren
    void viewStack(){
        if(stackTop > -1 ){
            cout << "Eleman sayisi : " << stackTop + 1 << "\nYiginin elemanlari :" << endl;
            for(int i = 0; i <= stackTop ; i++){
                cout << *(myArray + i) << endl;
            }
        }else{
            cout << "Yigin bos.. Elemanlar ekleyebilirsiniz" << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    // Stack emplementation
    
    Stack yigin;
    int userIsIn = true;
    int secin;
    
    while(userIsIn){
        cout << "Yapmak istediginiz islemi seciniz : \n1- Yığına eleman ekle \n2- Yığından eleman çıkar \n3- Yığındaki tüm elemanları göster \n4- Çıkış\nSescinizi girin : " << endl;
        cin >> secin;
        
        switch (secin) {
            case 1:
                yigin.push();
                break;
            case 2:
                yigin.pop();
                break;
            case 3:
                yigin.viewStack();
                break;
            case 4:
                userIsIn = false;
                cout << "GoodBye... ;)" << endl;
                break;
            default:
                cout << "Sadece 1,2,3 veya 4 girebilirsiniz" << endl;
                break;
        }
    }
    return 0;
}
