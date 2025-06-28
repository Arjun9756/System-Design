// Abstract factory method me ek factory 2 ya use jyda product create karti h
#include <bits/stdc++.h>
using namespace std;

// Singh Basic Burger Start
class Burger
{
public:
    virtual void createBurger() = 0;
    virtual ~Burger() {}
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
    void createBurger() override
    {
        cout << "Standard Burger Created" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void createBurger() override
    {
        cout << "Premium Burger Created" << endl;
    }
};
// Singh Basic Burger End

// Singh Wheat Burger Start
class BasicWheatBurger : public Burger
{
public:
    void createBurger() override
    {
        cout << "Basic Burger Created" << endl;
    }
};

class StandardWheatBurger : public Burger
{
public:
    void createBurger() override
    {
        cout << "Standard Burger Created" << endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void createBurger() override
    {
        cout << "Premium Burger Created" << endl;
    }
};
// Singh Wheat Burger End

// Basic Gralic Bread Class
class GarlicBread
{
public:
    virtual void createBread() = 0;
    ~GarlicBread() {}
};

class BasicBread : public GarlicBread
{
public:
    void createBread()
    {
        cout << "Creating Basic Garlic Bread" << endl;
    }
};

class StandardBread : public GarlicBread
{
public:
    void createBread()
    {
        cout << "Creating Standard Garlic Bread \n";
    }
};

class PremiumBread : public GarlicBread
{
public:
    void createBread()
    {
        cout << "Creating Premium Garlic Bread \n";
    }
};

// Basic Garlic Bread Class End

// Wheat Garlic Bread Class Start
class BasicWheatBread : public GarlicBread
{
public:
    void createBread() override
    {
        cout << "Creating Basic Wheat Garlic Bread" << endl;
    }
};

class StandardWheatBread : public GarlicBread
{
public:
    void createBread() override
    {
        cout << "Creating Standard Wheat Garlic Bread" << endl;
    }
};

class PremiumWheatBread : public GarlicBread
{
public:
    void createBread() override
    {
        cout << "Creating Premium Wheat Garlic Bread" << endl;
    }
};
// Wheat Garlic Bread Class End
class MealFactory
{
public:
    virtual Burger *createBurger(string &type) = 0;
    virtual GarlicBread *createBread(string &type) = 0;
    virtual ~MealFactory() {} // Virtual destructor for safety
};

class SinghExpertise : public MealFactory
{
public:
    Burger *createBurger(string &type) override
    {
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if (type == "basic")
            return new BasicBurger();
        if (type == "standard")
            return new StandardBurger();
        if (type == "premium")
            return new PremiumBurger();

        throw domain_error("No such burger type available!");
    }

    GarlicBread *createBread(string &type) override
    {
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if (type == "basic")
            return new BasicBread();
        if (type == "standard")
            return new StandardBread();
        if (type == "premium")
            return new PremiumBread();

        throw domain_error("No such garlic bread type available!");
    }
};

class KingExpertise : public MealFactory
{
public:
    Burger *createBurger(string &type) override
    {
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if (type == "basic")
            return new BasicWheatBurger();
        if (type == "standard")
            return new StandardWheatBurger();
        if (type == "premium")
            return new PremiumWheatBurger();

        throw domain_error("No such wheat burger type available!");
    }

    GarlicBread *createBread(string &type) override
    {
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if (type == "basic")
            return new BasicWheatBread();
        if (type == "standard")
            return new StandardWheatBread();
        if (type == "premium")
            return new PremiumWheatBread();

        throw domain_error("No such wheat garlic bread type available!");
    }
};

int main()
{
    MealFactory *factory = new KingExpertise();
    string burgerType = "Premium";
    string breadType = "Standard";

    try
    {
        Burger *burger = factory->createBurger(burgerType);
        GarlicBread *bread = factory->createBread(breadType);

        burger->createBurger();
        bread->createBread();

        delete burger;
        delete bread;
    }
    catch (const exception &e)
    {
        cerr << "Exception Caused What " << e.what();
    }
}