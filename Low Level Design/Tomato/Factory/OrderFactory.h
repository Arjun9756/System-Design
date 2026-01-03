#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include "../Models/Order.h"
#include "../Models/Cart.h"
#include "../Models/Restaurant.h"
#include "../Strategy/PaymentStrategy.h"
#include "../Models/MenuItem.h"
#include "../Models/User.h"

class OrderFactory{
public:
    virtual Order* createOrder(User *user, Cart *cart, Restaurant *res, const std::vector<MenuItem*> &menuItem, PaymentStrategy *pay, const std::string &type) = 0;
    virtual ~OrderFactory() {}
};

#endif