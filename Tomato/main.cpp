#include "Tomato.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Create Tomato app
    Tomato* tomato = new Tomato();

    User* user1 = new User(1, "Arjun", "Delhi");
    tomato->addUser(user1);

    Restaurant* rest1 = new Restaurant(1, "Bikaner", "Delhi");
    MenuItem* item1 = new MenuItem(101, "Chole Bhature", 120);
    rest1->addMenuItemRestaurant(item1);
    tomato->addRestaurant(rest1);

    tomato->addToCart(user1, item1);

    std::vector<MenuItem*> items = {item1};
    PaymentStrategy* pay = new CreditPay();
    Order* order = tomato->placeOrderNow(user1, rest1, items, pay, "Delivery");

    tomato->payForOrder(order);

    // Clean up
    delete tomato;
    delete user1;
    delete rest1;
    delete item1;
    delete pay;
    delete order;

    return 0;
}