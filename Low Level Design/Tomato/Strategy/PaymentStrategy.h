#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

class PaymentStrategy{
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

#endif
