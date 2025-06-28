#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
using namespace std;

class MenuItem{
private:
    int code;
    string name;
    double price;
public:
    MenuItem(int code , string name , double price){
        this->code = code;
        this->name = name;
        this->price = price;
    }

    int getMenuItemCode(){
        return this->code;
    }

    double getMenuItemPrice(){
        return this->price;
    }

    string getMenuItemName(){
        return this->name;
    }

    void setMenuItemPrice(double price){
        this->price = price;
    }

    void setMenuItemName(string name){
        this->name = name;
    }

    void setMenuItemCode(int code){
        this->code = code;
    }
};

#endif