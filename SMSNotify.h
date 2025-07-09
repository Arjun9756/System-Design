#ifndef SMS_NOTIFICATION_H
#define SMS_NOTIFICATION_H

#include "../Notification System/Notification.h"
#include "../Notification System/User.h"
#include <bits/stdc++.h>
using namespace std;

class SMSNotify : public Notification {
public:
    void sendNotification(User *user, string &content) override {
        if (user->getPhone().empty()) {
            cout << "Please provide the phone number\n";
            return;
        }

        cout << "SMS sent to: " << user->getPhone() << endl;
        Notification::saveToDB(user, content, "sms");
    }
};

#endif