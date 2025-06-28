#ifndef UPIPAY_H
#define UPIPAY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class UpiPay : public PaymentStrategy{
public:
    void pay(double amount){
        std::cout << "Paid " << amount << " using UPI" << std::endl;
    }
};

#endif