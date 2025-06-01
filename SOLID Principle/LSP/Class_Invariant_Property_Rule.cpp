// Porperty Rule state that if any parent class fixed a rule for itself then it should also be followed by its child class as well any how
// Example The balance in the account should always be greater than 0 

#include <bits/stdc++.h>
using namespace std;

//Invariant : Bal cannot be negative

class BankAccount{
public:
double balance;

    BankAccount(double balance){
        if(balance < 0)throw new runtime_error("Amount For deposit must be greater than 0");
        this->balance = balance;
    }

    virtual void withdraw(double amount) noexcept(false){
        if(amount <= this->balance){
            this->balance -= amount;
        }else{
            throw new runtime_error("Amount Must be greater than 0");
        }
    }
};

class CheatAccount : public BankAccount{
public:
    CheatAccount(double b) : BankAccount(b){}

    void withdraw(double amount) override {
        this->balance -= amount; // LSP Break Invariant Break
        cout<<"Amount withdraw current balance : "<<this->balance<<endl;
    }
};

int main() {
    BankAccount* acc = new CheatAccount(100);
    acc->withdraw(120);  

    delete acc;
    return 0;
}