#include <iostream>
using namespace std;

/*-----------  Author : JUDY NDOTONI NKWAMA   ---------*/

class Queue{
    
    int front=-1, rear=-1, tablo[4], bosyer = 4, kuyrukUzunlugu = 0;
    
public:
    //kuyruk bos olup olmadigina bakan
    bool isEmpty(){
        if( (rear == -1 && front == -1) ) return true;
        else return false;
    }
    // kuyrunun dolu olup olmadigina bakan
    bool isFull(){
        if( ((rear + 1) % 4) == front ) return true ;
        else return false;
    }
    
    //mevcut kutulara sayan
    int bosyerAl(){
        if(rear == -1 && front == -1){
            bosyer = 4;
        }else if(rear >= front){
            bosyer = 4 - (rear - front) - 1;
        }else{
            bosyer = 4 - ( (4 - front) + (rear + 1));
        }
        return bosyer;
    }
    
    int uzunluguAl(){
        return 4 - bosyerAl();
    }
    
    //eklleyen metot
    void enqueue(){
        if(!isFull()){
            if(isEmpty()){
                rear = 0;
                front = 0;
            }else{
                rear = (rear + 1) % 4;
            }
            int n;
            cout << "Eklemek istediginiz sayiyi girin : " << endl;
            cin >> n;
            tablo[rear] = n;
            cout << n << " elemani kuruga eklendi. tablo[" << rear << "]"<<  endl;
            cout << bosyerAl() << " adet bos yer var." << endl;
        
        }else{
            cout << "Kuyruk dolu oldugu icin ekleme islemi yapilmiyor..." << endl;
        }
        
    }
    
    //cikaran metot
    void dequeue(){
        if(isEmpty()){
            cout << "Kuyruk bos oldugu icin cikaracak bir sey yok..." << endl;
        }else{
            cout << "Cikarilmis eleman "  << tablo[front] << endl;
           if(rear == front){
               rear = -1;
               front = -1;
            }else{
                 front = (front + 1) % 4;
            }
            bosyerAl();
        }
    }
    
    //elemanlar yazdiran metot
    void showQueue(){
        if(isEmpty()){
            cout << "Kuyruk bos su an. Elemanlar ekleyebilirsiniz..." ;
        }else{
            cout << "Kuyruk elemanlari : " ;
            
            for (int i = front ; i <= rear; i++) {
                cout << tablo[i] << "   ";
            }
            
            if(!(rear >= front)){
                for (int i = front ; i < 4; i++) {
                    cout << tablo[i] << "   ";
                }
                for (int i = 0 ; i <= rear; i++) {
                    cout << tablo[i] << "   ";
                }
            }
            
            cout << endl;
        }
        
    }
};



int main(int argc, const char * argv[]) {
    // queu implementation (kuyruk uygulamasi)
    int userIsIn = true;
    int secin;
    
    Queue kuyruk;
    
    while(userIsIn){
        cout << "\n------------------------\n1- Kuyruğa eleman ekle \n2- Kuyruktan eleman çıkar \n3- Elemanları listele \n4- Çıkış\n------------------------\nSecinizi giriniz : " << endl;
        cin >> secin;
        
        switch (secin) {
            case 1:
                kuyruk.enqueue();
                break;
            case 2:
                kuyruk.dequeue();
                break;
            case 3:
                kuyruk.showQueue();
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
