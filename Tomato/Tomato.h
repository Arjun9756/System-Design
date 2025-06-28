#ifndef TOMATO_H
#define TOMATO_H

#include "Models/User.h"
#include "Models/Restaurant.h"
#include "Models/Cart.h"
#include "Manager/RestaurantManager.h"
#include "Manager/OrderManager.h"
#include "Strategy/PaymentStrategy.h"
#include "Strategy/CreditPay.h"
#include "Strategy/UpiPay.h"
#include "Factory/NowOrder.h"
#include "Factory/ScheduleFactory.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Tomato {
public:
    Tomato() {}

    void addUser(User* user) {
        users.push_back(user);
    }

    void addRestaurant(Restaurant* restaurant) {
        RestaurantManager::getInstance().addRestaurant(restaurant);
    }

    vector<Restaurant*> searchRestaurants(const string& location) {
        return RestaurantManager::getInstance().searchByLocation(location);
    }

    void addToCart(User* user, MenuItem* item) {
        user->getCart().addToCart(item);
    }

    Order* placeOrderNow(User* user, Restaurant* restaurant, vector<MenuItem*> items, PaymentStrategy* pay, const string& type) {
        Cart* cart = &user->getCart();
        for (auto item : items) {
            cart->addToCart(item);
        }
        NowOrder factory;
        Order* order = factory.createOrder(user, cart, restaurant, items, pay, type);
        OrderManager::getInstance().addOrder(order);
        return order;
    }

    Order* placeOrderScheduled(User* user, Restaurant* restaurant, vector<MenuItem*> items, PaymentStrategy* pay, const string& type) {
        Cart* cart = &user->getCart();
        for (auto item : items) {
            cart->addToCart(item);
        }
        ScheduleFactory factory;
        Order* order = factory.createOrder(user, cart, restaurant, items, pay, type);
        OrderManager::getInstance().addOrder(order);
        return order;
    }

    void payForOrder(Order* order) {
        order->payMoney();
    }

private:
    vector<User*> users;
};

#endif