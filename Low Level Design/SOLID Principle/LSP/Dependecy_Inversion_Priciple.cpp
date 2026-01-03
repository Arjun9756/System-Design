#include <iostream>
using namespace std;

// Abstraction
class IMessageService {
public:
    virtual void sendMessage(string message) = 0;
    virtual ~IMessageService() = default;
};

// Low-level module 1
class EmailService : public IMessageService {
public:
    void sendMessage(string message) override {
        cout << "Sending message through Email: " << message << endl;
    }
};

// Low-level module 2
class SMSService : public IMessageService {
public:
    void sendMessage(string message) override {
        cout << "Sending message through SMS: " << message << endl;
    }
};

// High-level module
class Notification {
private:
    IMessageService* service;

public:
    Notification(IMessageService* service) {
        this->service = service;
    }

    void notify(string message) {
        service->sendMessage(message);
    }
};

int main() {
    IMessageService* email = new EmailService();
    IMessageService* sms = new SMSService();

    Notification notifier1(email);
    notifier1.notify("Hello via Email");

    Notification notifier2(sms);
    notifier2.notify("Hello via SMS");

    delete email;
    delete sms;

    return 0;
}
