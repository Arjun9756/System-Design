#ifndef TIME_DECORATOR_H
#define TIME_DECORATOR_H

#include <bits/stdc++.h>
#include "../Notification System/NotifyDecorator.h"
using namespace std;


class TimeDecorator:public NotificationDecorator{
public:
    TimeDecorator(Notification *obj) : NotificationDecorator(obj){}
    void send(User *user , string &content)
    {
        content += " HH:MM:SS";
        cout<<"Time Appended On Notification String \n";
        warpper->sendNotification(user , content);
    }
};

#endif