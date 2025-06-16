// Factory method ke ander sub class ki responsiblity hoti h ki wo object create kare naki parent ye inheritace ke ek level ko oncrease krta h
#include <bits/stdc++.h>
using namespace std;


//Singh Burger Start
class Burger
{
public:
    virtual void createBurger() = 0;
    virtual ~Burger(){}
};

class BasicBurger : public Burger
{
public:
    void createBurger() override 
    {
        cout << "Basic Burger Created" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void createBurger()override 
    {
        cout << "Standard Burger Created" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void createBurger()override 
    {
        cout << "Premium Burger Created" << endl;
    }
};
//Singh Burger End

// King Burger Start
class BasicWheatBurger : public Burger{
public:
    void createBurger() override{
        cout<<"Creating Basic Wheat Burger\n";
    }
};

class StandardWheatBurger : public Burger{
public:
    void createBurger()override{
        cout<<"Creating Standard Wheat Burger\n";
    }
};

class PremiumWheatBurger : public Burger{
public:
    void createBurger()override{
        cout<<"Creating Premium Wheat Burger\n";
    }
};

class Factory{
public: 
    virtual Burger* createBurgerObject(string &type) = 0;
};

class SinghBurger : public Factory{
public: 
    Burger *createBurgerObject(string &burger){
        transform(burger.begin(), burger.end(), burger.begin(), [](char &c){
            return tolower(c);
        });

        if (burger == "basic")
        {
            return new BasicBurger();
        }
        else if (burger == "standard")
        {
            return new StandardBurger();
        }
        else if (burger == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            throw std::domain_error("Illegal burger type input");
        }
    }
};

class KingBurger : public Factory{
public:
    Burger *createBurgerObject(string &burger){
        transform(burger.begin(), burger.end(), burger.begin(), [](char &c){
            return tolower(c);
        });

        if (burger == "basic")
        {
            return new BasicWheatBurger();
        }
        else if (burger == "standard")
        {
            return new StandardWheatBurger();
        }
        else if (burger == "premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            throw std::domain_error("Illegal burger type input");
        }
    }
};

int main()
{
    string type = "basic";
    try
    {
        Factory *factory = new KingBurger();
        Burger *burger = factory->createBurgerObject(type);
        burger->createBurger();
    }
    catch(const exception *e){
        cout<<"Exception Caused What : "<<e->what();
    }
}