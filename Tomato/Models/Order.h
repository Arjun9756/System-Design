#ifndef ORDER_H
#define ORDER_H

#include "Restaurant.h"
#include "MenuItem.h"
#include "../Strategy/PaymentStrategy.h"
#include "User.h"
#include "Cart.h"

class Order{
private:
    static int nextId;
    int orderId;
    vector<MenuItem*>menu;
    Restaurant *res;
    PaymentStrategy *pay;
    User *user;
    Cart *cart;
    double total;
    string scheduled;
public:

    Order(){
        this->orderId = ++nextId;
        this->res = nullptr;
        this->pay = nullptr;
        cart = nullptr;
        this->user = nullptr;
    }
    virtual ~Order() {}
    virtual string typeOfOrder() = 0;

    void setOrderId(int id){
        this->orderId = id;
    }

    void payMoney(){
        if(!pay or pay == nullptr){
            cout<<"Set Payment Method \n";
        }
        pay->pay(total);
    }

    void addMenuItem(MenuItem *item){
        this->menu.push_back(item);
    }

    void setRestaurant(Restaurant *res){
        this->res = res;
    }

    void setPayment(PaymentStrategy *p){
        this->pay = p;
    }

    void setUser(User *us){
        this->user = us;
    }

    void setSchedule(string sch){
        this->scheduled = sch;
    }

    void setMenuItem(vector<MenuItem*>men){
        this->menu = men;
    }

    vector<MenuItem*>getMenu(){
        return this->menu;
    }

    double getTotal(){
        double amount = 0.0;
        for(auto it : this->menu)
        {
            amount += it->getPrice();
        }
        return amount;
    }

    User *getUser(){
        return this->user;
    }
    Restaurant *getRestaurant(){
        return this->res;
    }

    int getOrderId(){
        return this->orderId;
    }

    string getScheduled(){
        return this->scheduled;
    }

    PaymentStrategy *getPaymentMode(){
        return this->pay;
    }

    void setCart(Cart *cart){
        this->cart = cart;
    }

    Cart *getCart(){
        return this->cart;
    }

};

int Order::nextId = 0;

#endif