#include <bits/stdc++.h>
using namespace std;

// Factory design pattern ek esa pattenr hota h jo object creation prcoess or business logic ko seprate rkhta h 
// Ye code ki flexibilty ko or jyda improve krta kyuki humko bar bar same object nhi create karna pdta h

// 1. Simple Method => Isme input ke baisis per Hum Object create karte h

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

class Factory
{
public:
    Burger *burgerType(string &burger)
    {

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

int main()
{
    string type = "standard";
    Factory factory;

    try
    {
        Burger *burger = factory.burgerType(type);
        burger->createBurger();
    }
    catch(const exception *e)
    {
        cout<<"Exception Caused what : "<<e->what();
    }
    return 0;
}