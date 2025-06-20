// Singleston design pattern ek esa pattern hota h jha per hum sirf class ka ek hi object create karte h or wo object sab kaam ke liye responsible hota h 
// ese object ki kya need h iski need isliye h taki hum jo resource sharing chiz h jese database unko sirf ek hi object se handle kar pye naki bhotto se verna 
// data ki inconssistence bn jygi

#include <bits/stdc++.h>
using namespace std;

class Singleton{
private:
    static Singleton *instance;
    static mutex mtx;

    Singleton(){
        cout<<"Singleton Constructor called. New Object Created yet \n";
    }

public:
    static Singleton *getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton :: instance = nullptr;
mutex Singleston::mtx; 

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout<<(s1 == s2) ? true : false;
}