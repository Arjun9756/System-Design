/**
 * Polymorsphism is a greek word which means that ability to take more than one form ??? means where single object is treater differently depending upon the
 * context and the situation ?? can we explore with an example yes
 * 
 * Let's take the person object okay if person is on school or college it will be treated as student same person is standing on market will be treated as 
 * customer same person standing on the home will be treated as son which means the object is same but its total y depends upon the conetex and the environment 
 * how the object is going to bet treated
 * 
 * One thing i clear to you that there is the use of virtual why ?? whats actual need over here ??
 * So first think that whenever we create a pointer we have to asssign the address of the same data type of pointer we have created like int with int 
 * same implies on object as well not think that parent and child class has relation yes or not yes and parent is always bigger than child yes or no absolutely yes
 * now which means that we can assing the child class addres to parent class becuase its an higher authority it cnan handle it but child class pointer cannot handle parent one
 * 
 * Thats the problem arises when the base class pointer is assign the address of child one and with the help of parent class pointer if we call the child class
 * function then parent class function get called ?? but we have called child class function as the parent contains the address of child so it should execute ??
 * 
 * Yes your thinking is correct but the c++ do early binding over here which means that the function call will connect to the function defintion at compile time
 * not at run time at compile time parent does not having the address of child becuase the memeory is allocated at runtime not at compile time thats why
 * 
 * virtual keyword ensure to block early binding and enables late binding
 */

#include <bits/stdc++.h>
using namespace std;

class Person{
public:
    virtual void role(){
        cout<<"I am a Person \n";
    }
};

class School : public Person{
public:
    void role()override{
        cout<<"I am Person Object But in School \n";
    }
};

class Market : public Person{
public:
    void role()override{
        cout<<"I am Person Object But in Market \n";
    }
};

int main()
{
    Person *p;
    School s;
    Market m;

    p = &s;
    p->role();
    p = &m;
    p->role();

    delete p;
}