// Return type rule states that a child class can only return the value from the method of the same data type as of parent class method
// Or can return the value of its child class but it not possible that a child class returns an object or value of its parent of parent class

#include <bits/stdc++.h>
using namespace std;

class Animal{

};

class Dog : public Animal{

};

class Parent{
public:
    virtual Animal *getAnimal(){
        cout<<"Returning Animal class object \n";
        return new Animal();
    }
};

class Child : public Parent{
public:
    Dog* getAnimal(){
        cout<<"Returning child class object ya DOG \n";
        return new Dog();
    }
};

class Client{
private:
    Parent *p;
public:
    Client(Parent *p){
        this->p = p;
    }

    void getAnimal(){
        p->getAnimal();
    }
};

int main(){
    Parent *p = new Parent();
    Child *c = new Child();

    Client *c2 = new Client(p);
    c2->getAnimal();
}