/**
 * Okay so inheritance is basically a capability in which one class inherit the properties of the another class. The class which is giving up the 
 * properties is known as the parent class or the base class and the class which is taking out the properties is known as the child class. Inheritance 
 * basically shows the is-are relationship. okay so 
 * inheritance why do you if we say that why to use the inheritance? so inheritance basically helps us to avoid the rewriting of the code again and again and
 * increases the overall scalability and maintainbility of the codebase
 * 
 * 1. Single Level A <-- B
 * 2. Multi Level A <-- B <-- C
 * 3. Multiple A <-- B <-- C ,    (B,C) <-- D
 * 
 *  Drill Note
 * Virtual Function Ensures The Runtime Polymorphism
 * But Virtual in Case of Inheritance tells that only one copy of parent class will be shared to that class who is inheriting it if they create a chain of 
 * inheritance then also one copy 
 * 
 * Inheritance is (is a relation) Say Like Animal <-- Dog then Dog is a Animal or Animal <-- Cow then cow is animal (is a)
 * Solution of Inheirtance is not more inheritance everytime for exmaple Bank class now inheirt by two class saving and current 
 * saving class increase level of inheitance private customer , public customer , currennt class private , public customer
 * now public customer class of both increases level of rural , urban basically for every inheritance solution to inheirtnace is not more inheirtance insead we 
 * should go for composition Like 
 * 
 * Class CustomerType (private , public)
 * AccountType (saving , current)
 * Location (rural , urban)
 * 
 * now create Object of Account ()
 */

#include <bits/stdc++.h>
using namespace std;

// Problem of Inheritance Explodes of Inheirtance .....
class Account{};
class savingAccount : public Account{};
class currentAccount : public Account{};
class Customer{};
class publicCustomer:public Customer{};
class privateCustomer:public Customer{};
class Area{};
class ruralArea:public Area{};
class urbanArea:public Area{};

// Cleaner Version
class CustomerType{};
class Location{};
class AccountType{}; 

// That's All

class A{
public:
    void show(){
        cout<<"A Show Function \n";
    }
};

class B : virtual public A{
public:
    void show(){
        cout<<"B Show Function \n";
    }
};

class C : virtual public A{
public: 
    void show(){
        cout<<"C Show Function \n";
    }
};

class D : public C , public B{
public:
    void show(){
        cout<<"D Show Function \n"; // Inheritance.cpp:37:7: warning: direct base 'A' inaccessible in 'D' due to ambiguity
    }
};

int main(){
    D *d1 = new D();
    d1->show();

    B *b1 = new B();
    b1->show();

    delete d1;
    delete b1;
}