#include "./TimeDecorator.h"
#include "./SMSNotify.h"
#include "./User.h"

int main()
{
    User *user = new User("Amit", "1234567890" , "amit@gmail.com");
    string message = "Hello, this is your notification";

    Notification *sms = new SMSNotify();
    Notification *timedSMS = new TimeDecorator(sms);

    timedSMS->sendNotification(user , message);
    delete timedSMS;
    delete sms;
    delete user;
    return 0;
} 