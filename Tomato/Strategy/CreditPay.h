#ifndef CREDITPAY_H
#define CREDITPAY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class CreditPay : public PaymentStrategy{
public:
    void pay(double amount){
        std::cout << "Paid " << amount << " using Credit Card" << std::endl;
    }
};

#endif
