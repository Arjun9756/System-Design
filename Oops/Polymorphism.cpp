#include <bits/stdc++.h>
using namespace std;

// Function Overloading or Static or Compile time polymorphism

void show(string name , string age){
    cout<<name <<" "<<age<<endl;
}

void show(string name){
    cout<<name<<endl;
}

// Function Overloading or Static or Compile time polymorphism

class Car{
public:
    string name;
    string model;
    string brand;

    virtual void accelerate() = 0;
    string getName(){return this->name;};
    string getModel(){return this->model;}
    string brand(){return this->brand;}
};

class Manual  : public Car{
public:

    Manual(string name, string model, string brand) {
        this->name = name;
        this->model = model;
        this->brand = brand;
    }

    void accelerate(){
        cout<<"Accerlerate success"<<endl;
    }
};

int main()
{
    Manual m("Swift", "2024", "Suzuki");
    m.accelerate();
    cout << "Name: " << m.getName() << endl;
    cout << "Model: " << m.getModel() << endl;
    cout << "Brand: " << m.getBrand() << endl;

    return 0;
}