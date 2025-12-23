#include <bits/stdc++.h>
using namespace std;

/**
 * This pointer is a special type of pointer which points to the current object so that whenever a function is get called so it can have the knowldege
 * who has called it
 * 
 * Why is is neede
 * This pointer is neede to remove the confusion between the class variable and the function paramter for exmpale your class has varibale name
 * and a function set is taking parameter @param name as input and you want to store the class variable name = function vairbale name this create an 
 * confusion for the compiler who is which one ???
 * 
 * It also uses for the method chaining
 * When ever we call like obj->method(); actualy c++ send it like this method(&obj , parameters)  obj is this pointer
 */

class Demo{
public:
    string name;
    int count = 0;

    void setName(string name){
        // name = name;  create confusion who is which one
        this->name = name;    // This is pointing to current object
    }

    Demo *counter(){
        cout<<++count<<" ";
        return this;
    }
};

int main()
{
    Demo *d1 = new Demo();
    d1->setName("hsuk");
    d1->counter()->counter();    // Method Chaining 
}