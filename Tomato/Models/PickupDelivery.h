#ifndef PICKUPDELIVERYORDER_H
#define PICKUPDELIVERYORDER_H

#include "Order.h"
#include <string>
using namespace std;

class PickupDeliveryOrder : public Order{
private:
    string address;
public:
    string typeOfOrder(){
        return "pickup";
    }
    void setRestaurantAddress(string add){
        this->address = add;
    }
    string getRestaurantAddress(){
        return this->address;
    }
};

#endif