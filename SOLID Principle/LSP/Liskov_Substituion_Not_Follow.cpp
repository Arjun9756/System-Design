// LSP Priciples says that the child class should be usable in place of its parent class whithout breaking the main functionality
// Means Agr khi parent class ka pointer pass h toh hum usko child class ka pointer assign kre toh koi bhi dikat nhi honi chiye

#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    virtual void deposit(double balance) = 0;
    virtual void withdraw(double balance) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount() { this->balance = 0.0;}
    void deposit(double balance)
    {
        this->balance += balance;
    }

    void withdraw(double amount)
    {
        if (amount <= this->balance)
        {
            this->balance -= amount;
            cout << "Current Balance after withdraw is " << this->balance << endl;
        }
        else
        {
            cout << "Not Suffcient Balance \n";
        }
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount() { this->balance = 0.0;}
    void deposit(double balance)
    {
        this->balance += balance;
    }

    void withdraw(double amount)
    {
        if (amount <= this->balance)
        {
            this->balance -= amount;
            cout << "Current Balance after withdraw is " << this->balance << endl;
        }
        else
        {
            cout << "Not Suffcient Balance \n";
        }
    }
};

class FixedTermAccount : public Account{
private:
    double balance;
public:

    FixedTermAccount(){this->balance = 0.0;}
    void deposit(double amount){
        this->balance += amount;
    }

    void withdraw(double amount){
        throw logic_error("Withdraw is not allowed in Fixed Term Account");
    }
};

class BankClient{
private:
    vector<Account*>accounts;
public:
    BankClient(vector<Account*>account){
        this->accounts = account;
    }

    void processTxn(){
        for(auto acc : accounts){
            acc->deposit(1000);
            try{
                acc->withdraw(500);
            }
            catch(const exception &e){
                cout<<"Exception caused : "<<e.what() <<endl;
            }
        }
    }
};

int main() {
    vector<Account*> accounts;

    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTxn();

    return 0;
}
