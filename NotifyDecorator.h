#ifndef NOTIFICATION_DECORATOR_H
#define NOTIFICATION_DECORATOR_H

#include <bits/stdc++.h>
#include "../Notification System/Notification.h"
using namespace std;

class NotificationDecorator : public Notification{
public:
    Notification *warpper;
    NotificationDecorator(Notification *n){
        this->warpper = n;
    }

    void sendNotification(User *user , string &content){
        warpper->sendNotification(user , content);
    }
};

#endif