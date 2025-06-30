#include <iostream>
#include <string>
using namespace std;


class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paying ₹" << amount << " using UPI Payment." << endl;
    }
};

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paying ₹" << amount << " using Credit Card." << endl;
    }
};

class UpiViaQR : public UpiPayment {
public:
    void pay(int amount) override {
        cout << "Paying ₹" << amount << " using UPI via QR Code." << endl;
    }
};

class UpiViaID : public UpiPayment {
public:
    void pay(int amount) override {
        cout << "Paying ₹" << amount << " using UPI via UPI ID." << endl;
    }
};


class VisaCardPayment : public CreditCardPayment {
public:
    void pay(int amount) override {
        cout << "Paying ₹" << amount << " using Visa Credit Card." << endl;
    }
};

class MasterCardPayment : public CreditCardPayment {
public:
    void pay(int amount) override {
        cout << "Paying ₹" << amount << " using MasterCard Credit Card." << endl;
    }
};

class PaymentProcessor {
private:
    PaymentStrategy* strategy;

public:
    void setStrategy(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void makePayment(int amount) {
        if (strategy)
            strategy->pay(amount);
        else
            cout << "No payment method selected." << endl;
    }
};


int main() {
    PaymentProcessor processor;

    UpiViaQR upiQr;
    processor.setStrategy(&upiQr);
    processor.makePayment(1500);

    UpiViaID upiId;
    processor.setStrategy(&upiId);
    processor.makePayment(1200);

    
    VisaCardPayment visa;
    processor.setStrategy(&visa);
    processor.makePayment(3000);

    MasterCardPayment mastercard;
    processor.setStrategy(&mastercard);
    processor.makePayment(2800);

    return 0;
}
