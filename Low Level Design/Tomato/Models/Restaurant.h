#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "MenuItem.h"
#include <vector>
#include <string>

class Restaurant{
private:
    int id;
    string name;
    string address;
    vector<MenuItem*>menu;
public:
    Restaurant(int id , string name , string address){
        this->id = id;
        this->name = name;
        this->address = address;
    }

    void setRestaurantId(int id){
        this->id = id;
    }

    void setRestaurantName(string name){
        this->name = name;
    }

    void setRestaurantAddress(string address){
        this->address = address;
    }

    string getRestaurantAddress(){
        return this->address;
    }

    int getRestaurantId(){
        return this->id;
    }

    string getRestaurantName(){
        return this->name;
    }

    void addMenuItemRestaurant(MenuItem *menu){
        this->menu.push_back(menu);
    }

    // void deleteMenuItemRestuarant(int code)
    // {
    //     Write Your Logic
    // }
}

#endif