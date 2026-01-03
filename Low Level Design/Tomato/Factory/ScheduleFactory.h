#ifndef SCHEDULEFACTORY_H
#define SCHEDULEFACTORY_H

#include "OrderFactory.h"
#include "../Models/OnDeliveryOrder.h"
#include "../Models/PickupDelivery.h"
#include "../Strategy/PaymentStrategy.h"
#include "../Models/Cart.h"
#include "../Models/MenuItem.h"
#include <string>
#include <vector>

class ScheduleFactory : public OrderFactory{
public:
    Order* createOrder(User *user, Cart *cart, Restaurant *res, const std::vector<MenuItem*> &menuItem, PaymentStrategy *pay, const std::string &type) override {
        Order *order = nullptr;
        if(type == "Delivery"){
            auto deliveryOrder = new OnDeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        } else {
            auto pickupOrder = new PickupDeliveryOrder();
            pickupOrder->setRestaurantAddress(res->getRestaurantAddress());
            order = pickupOrder;
        }
        order->setUser(user);
        order->setRestaurant(res);
        order->setMenuItem(menuItem);
        order->setPayment(pay);
        order->setCart(cart);
        order->setSchedule("Scheduled");
        return order;
    }
};

#endif