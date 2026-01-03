#ifndef ONDELIVERYORDER_H
#define ONDELIVERYORDER_H

#include "Order.h"
#include <string>
using namespace std;

class OnDeliveryOrder : public Order{
private:
    string address;
public:
    string typeOfOrder(){
        return "delivery";
    }
    void setUserAddress(string add){
        this->address = add;
    }
    string getUserAddress(){
        return this->address;
    }
};

#endif