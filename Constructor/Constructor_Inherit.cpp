#include <bits/stdc++.h>
using namespace std;

/**
 *  Output Of This Code
 
    Parent Constructor
    Child Constructor
    Child Destructor
    Parent Destructor

 * In Case Inheritance constructor behave differently when child class object is created then firts parent class constructor is executed then child constructor 
 * is excecuted but in case of destructor child is deleted so first child class destructor runs then after parent class destructor
 * 
 * Constructor Case Calling Sequnce ( Child --> Parent ) But Execution Sequence (Parent --> Child)
 * Destructor Case Calling Sequence ( Child --> Parent ) But Exectuion Sequence is Same ( Child --> Parent )
 * 
 * Why this happens If i create child class object so first child constructor should be excuted na ??
 * Think logically in respective of child class before the child creation first her parent should be created na without parent how a child class can be there 
 * Same for constructor child class will first destroyed then after parent class will destroyed to release the resource

 */

class Parent
{
public:
    Parent()
    {
        cout << "Parent Constructor \n";
    }

    ~Parent()
    {
        cout << "Parent Destructor \n";
    }
};

class Child : public Parent
{
public:
    Child() : Parent()
    {
        // To Acces Parent Data use like Parent::method()
        cout << "Child Constructor \n";
    }

    ~Child()
    {
        cout << "Child Destructor \n";
    }
};

int main()
{
    Child *c1 = new Child();
    delete c1;
}