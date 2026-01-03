// ISP states that no class should be forces to implement that method that they dont won't to use it should be seprate from other
#include <bits/stdc++.h>
using namespace std;

class 2DShape{
public:
    virtual void area(double side) = 0;
};

class 3DShape{
public:
    virtual void volume(double side) = 0;
};

class Square : public 2DShape{
private:
    double side;
public: 
    double area(double side){
        return side * side;
    }
};

void Cube : public 3DShape , public 2DShape{
private:
    double side;
public:
    double area(double side){
        return side * side * side;
    }

    double volume(double l , double b , double h){
        return l*b*h;
    }
}

int main(){
    Cube *c1 = new Cube();
    c1->area(5.4);
    c1->volume(4 , 5 , 2);
}