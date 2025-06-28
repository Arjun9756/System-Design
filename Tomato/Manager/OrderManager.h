#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "../Models/Order.h"
#include <vector>

class OrderManager{
private:
    std::vector<Order*> orders;
public:
    void addOrder(Order* order){
        orders.push_back(order);
    }
    std::vector<Order*> getOrders(){
        return orders;
    }
};

#endif