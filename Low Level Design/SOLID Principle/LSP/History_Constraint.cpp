// History constraint says that the history which is created by the parent class must be followed by its child class as well
#include <bits/stdc++.h>
using namespace std;

class Account{
public:
    virtual void withdraw(double amount) = 0;
};

class FixedTermAccount : public Account{
private:
    double balance;
public:
    FixedTermAccount():balance(50000){}
    void withdraw(double amount){
        throw new domain_error("This function is not allowed to you !!");
    }
};

int main()
{
    FixedTermAccount *f1 = new FixedTermAccount();
    try{
        f1->withdraw(3000);
    }catch(const logic_error *e){
        cout<<e->what()<<endl;
    }
}