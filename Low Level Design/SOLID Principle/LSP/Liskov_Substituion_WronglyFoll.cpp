// Liskov substruction principle says that if child class should be usable in plcae of parent class
// Means agr hum parent class ke pointer ki jagh child class ka pointer assign kre toh koi dikat nhi honi chiye
// Yha per hum liskov follwed krenge lekin wrong way me jise OPEN - CLOSE principle unfollow hoga

#include <bits/stdc++.h>
using namespace std;

class Account
{
private:
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount() { this->balance = 0.0; }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
        }
        else
        {
            return;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= this->balance)
        {
            this->balance -= amount;
        }
        else
        {
            cout << "No Enough Balance \n";
            return;
        }
    }
};

class CurrentAccount : public Account
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
        }
        else
        {
            cout << "No Enough Balance is Available \n";
            return;
        }
    }
};

class FixedTermAccount : public Account
{
private:
    double balance;

public:
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

    void withdraw(double amount){
        // Override
    }
};

class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account*>accounts){
        this->accounts = accounts;
    }

    void processTXN()
    {
        for (auto acc : accounts)
        {
            if (typeid(*acc) == typeid(FixedTermAccount))
            {
                cout << "Skipping Withdraw of Fixed Term Account \n";
            }
            else
            {
                acc->deposit(1000);
                acc->withdraw(500);
            }
        }
    }
};

int main()
{
    vector<Account *> accounts;

    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient *client = new BankClient(accounts);
    client->processTXN();

    return 0;
}