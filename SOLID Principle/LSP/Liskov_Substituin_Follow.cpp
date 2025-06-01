// Yha per 2 abstract class bne EK Withdrwable or ek Non Withdraable withdrwable me khali withdrwa hoga  ye class Non with drwa ko inherit kregi jisme deposit 
// hoga means deposit apne ap ajyga

#include <bits/stdc++.h>
using namespace std;

class NonWithdrawable{
public:
    virtual void deposit(double amount) = 0;
};

class Withdrawable : public NonWithdrawable{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Withdrawable{
private:
    double balance;
public:

    SavingAccount():balance(0.0){}

    void withdraw(double amount){
        if(amount <= this->balance){
            this->balance -= amount;
            cout<<"Withdraw successful from saving account current amount is : "<<this->balance<<endl;
        }else{
            cout<<"No Enough Balance : "<<this->balance;
            return; 
        }
    }

    void deposit(double amount){
        if(amount > 0){
            this->balance += amount;
        }else{
            cout<<"Amount must be greater than 0 \n";
        }
    }
};

class CurrentAccount : public Withdrawable
{
private:
    double balance;

public:
    CurrentAccount() : balance(0.0) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
        }
        else
        {
            cout << "Amount Must Be Greater Than 0 \n";
            return;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= this->balance)
        {
            this->balance -= amount;
            cout<<"Withdraw from current account current balance : "<<this->balance<<endl;
        }
        else
        {
            cout << "No Enough Balance is Available \n";
            return;
        }
    }
};

class FixedTermAccount : public NonWithdrawable{
private:
    double balance;
public:

    FixedTermAccount():balance(0.0){}

    void deposit(double amount){
        if(amount > 0){
            this->balance += amount;
        }
    }
};

class BankClient{
private:
    vector<Withdrawable*>withdrawableAccount;
    vector<NonWithdrawable*>nonWithdrawableAccount;

public:

    BankClient(vector<Withdrawable*>withdrawableAccount , vector<NonWithdrawable*>nonWithdrawableAccount){
        this->withdrawableAccount = withdrawableAccount;
        this->nonWithdrawableAccount = nonWithdrawableAccount;
    }

    void processTXN(){
        for(auto with : withdrawableAccount){
            with->deposit(1000);
            with->withdraw(500);
        }

        for(auto nowith : nonWithdrawableAccount){
            nowith->deposit(1000);
        }
    }
};

int main(){

    vector<Withdrawable*>withdrawableAccount;
    vector<NonWithdrawable*>nonWithdrawableAccount;

    SavingAccount *s1 = new SavingAccount();
    CurrentAccount *c1 = new CurrentAccount();

    FixedTermAccount *f1 = new FixedTermAccount();
    withdrawableAccount.push_back(s1) , withdrawableAccount.push_back(c1);

    nonWithdrawableAccount.push_back(f1);
    BankClient *b1 = new BankClient(withdrawableAccount , nonWithdrawableAccount);

    b1->processTXN();
}