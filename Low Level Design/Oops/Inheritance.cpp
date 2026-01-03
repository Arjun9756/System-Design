#include <bits/stdc++.h>
using namespace std;

/*

Inheritance is basically an capability where one class inherit the properites of another class the class which is giving the properties is know
as Parrent class abd rge ckass wghich is taking the properties is kbow as child class

*/

class Parent{
public:
    string name;
    int price;

    Parent(string name , int price):price(price) , name(name){}
    string getName(){return this->name;}
    int getPrice(){return this->price;}
};

class Child : public Parent{
public:
    float rating;
    Child(string name , int price , float rating) : Parent(name , price){
        this->name = name;
        this->price = price;
        this->rating = rating;
    }
};

int main()
{
    Child c1("Samsung" , 32000 , 10);
    cout<<c1.getPrice();
}