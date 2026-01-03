/**
 * Encapsulation is a process of wrapping out the whole data under a single unit which is know as class so that no other third party function can directly
 * access it.
 * 
 * Why there is the need of Encapsulation ????
 * 1. Data Security = Encapsulation ensures that data should be secure from the ousider function they should not be allow to do so that else there may be issue of data 
 *                    consistency and misresults also.
 * 
 * 2.Data Integrity = Encapsulation only allows the inner function to make modification in data while maintaing the integrity of we can say while following the
 *                    rules for that data like bank balance >= 0 always after dedcuting the same
 * 
 * 3.Data Hiding = It hides the data from the outsider function to prevent the sensitive data 
 */

#include <bits/stdc++.h>
using namespace std;

class Encapsulation{
private:
    string name;
    double balance = 0.0;
public:
    Encapsulation(string name , double balance){
        this->balance = (balance > 0.0 ? balance : 0.0);
        this->name = name;
    }

    void depositBalance(double balance){
        this->balance += (balance > 0.0 ? balance : 0.0);
    }

    double getBalance(){
        return this->balance;
    }

    bool deductBalance(double balance){
        if(this->balance >= balance and balance > 0.0){
            this->balance -= balance;
            return true;
        }
        return false;
    }
    ~Encapsulation(){
        cout<<"Customer Deleted \n";
    }
};

int main(){
    Encapsulation *e1 = new Encapsulation("Kush" , 89550.00);
    cout<<e1->deductBalance(550)<<endl;

    // No Direct Access Possible to dedcut balance without object
    delete e1;
}