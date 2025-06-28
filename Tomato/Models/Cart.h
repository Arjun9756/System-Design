#ifndef CART_H
#define CART_H

#include "MenuItem.h"
#include <vector>
#include <iostream>
using namespace std;

class Cart{
private:
    vector<MenuItem*>menu;
public:
    Cart(vector<MenuItem*>menu){
        this->menu = menu;
    }

    void addToCart(MenuItem*menu){
        this->menu.push_back(menu);
    }

    void clearCart(){
        this->menu.clear();
        cout<<"Cart Is Cleared \n";
    }

    double totalPrice(){
        double amount = 0.0;
        for(auto it : this->menu){
            amount += it->getPrice();
        }

        return amount;
    }
};

#endif