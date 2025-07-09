#ifndef WHATSAPP_H
#define WHATSAPP_H

#include <bits/stdc++.h>
#include "Notification System/Notification.h"
using namespace std;

class Whatsapp : public Notification{
public:
    void sendNotification(User *user , string content){
        if(!user->getPhone()){
            cout<<"PLease Provide the Contact Info \n";
            return;
        }

        cout<<"Whatsapp message Sent to : "<<user->getPhone();
        Notification::saveToDB(user , content , "whatsapp");
    }
};

#endif