// Exception rule states tha a child class should only throw the exception of the its Same as parent class or child class of exception class mention in parent class
// If it throw the exception of class of its parent of parent or any other one leads to an error

// std::logic_error      --> compile-time or input validation errors
// │
// ├── std::invalid_argument
// ├── std::domain_error
// ├── std::length_error
// └── std::out_of_range

// std::runtime_error    --> runtime/unchecked errors
// ├── std::range_error
// ├── std::overflow_error
// └── std::underflow_error

#include <bits/stdc++.h>
using namespace std;

class Parent
{
public:
    virtual void getValue() noexcept(false)
    {
        throw new logic_error("Something went wrong");
    }
};

class Child : public Parent
{
public:
    void getValue() noexcept(false)
    {
        throw new domain_error("Something went wrong in domain error");
    }
};

class Client
{
private:
    Parent *p;

public:
    Client(Parent *p){
        this->p = p;
    }
    void takeValue()
    {
        try
        {
            p->getValue();
        }
        catch (const runtime_error *e)
        {
            cout << e->what();
        }
    }
};

int main()
{
    Parent *p = new Parent();
    Child *c = new Child();

    Client *client1 = new Client(p);
    client1->takeValue(); 

    cout<<endl;

    Client *client2 = new Client(c);
    client2->takeValue(); 

    return 0;
}
