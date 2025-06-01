#include <bits/stdc++.h>
using namespace std;

/* 

Abstraction simply means that providing the essential details of a object without including the background
of the Object As it says for the data hiding from the User 

Means User is not being recomended to know the internal working of the function but if they it will not cause any problem

*/

class Fridge{
public:
    string name;
    string capacity;
    string price;
    float rating;

    Fridge(string name , string capcity , string price , float rating) {
        this->name = name;
        this->capacity = capacity;
        this->price = price;
        this->rating = rating;
    }

    string getName(){return this->name;}
    string getCapacity(){return this->capacity;}
    string getPrice(){return this->price;}
    int getRating(){return this->rating;}
};

int main()
{
    Fridge f1("Samung 2" , "48 Litres" , "32000" , 4.5);
    cout<<f1.getName();
}