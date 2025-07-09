#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <bits/stdc++.h>
#include <User.h>
#include <../Notification System/Database.h>
using namespace std;

// Pure Abstract Class
class Notification{
public:
    virtual void sendNotification(User *user , string &content) = 0;
    ~Notification(){}
    static void saveToDB(User *user , string content , string service)
    {
        Database::getInstance()->saveToDB(user, content, service);
    }
};

#endif