#ifndef USER_H
#define USER_H

#include "Cart.h"
#include <string>

class User{
private:
    static int nextId;
    int id;
    std::string name;
    std::string address;
    Cart cart;
public:
    User(int id , std::string name , std::string address){
        this->id = ++nextId;
        this->name = name;
        this->address = address;
    }

    std::string getName(){
        return this->name;
    }
    std::string getAddress(){
        return this->address;
    }

    int getId(){
        return this->id;
    }

    void setId(int id){this->id = id;}
    void setName(std::string name){this->name = name;}
    void setAddress(std::string add){this->address = add;}
};

int User::nextId = 0;

#endif