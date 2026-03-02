#include <bits/stdc++.h>
#include <mutex>
#include <ctime>
#include <memory>
#include <windows.h>
#include <thread>
using namespace std;

class User{
public:
    int id;
    string name;
    string email;
    bool isActive;
    string phone;

    User(int id , string name , string email , bool isActive = true , string phone = ""){
        this->id = id;
        this->name = name;
        this->email = email;
        this->isActive = isActive;
        this->phone = phone;
    }

    User(){
        id = 0;
        name = "";
        email = "";
        isActive = false;
        phone = "";
    }

    string getName(){return this->name;}
    string getPhone(){return this->phone;}
    int getId(){return this->id;}
    string getEmail(){return this->email;}
    bool isActiveUser(){return this->isActive;}
};

class Products{
public:
    int id;
    int stockCount;
    string name;
    bool stockAvailable;

    Products(){
        id = 0;
        stockCount = 0;
        name = "";
        stockAvailable = false;
    }

    Products(int id , int stockCount , string name , bool inStock = true){
        this->id = id;
        this->stockCount = stockCount;
        this->name = name;
        this->stockAvailable = inStock;
    }

    int getId(){return this->id;}
    int getStock(){return this->stockCount;}
    string getName(){return this->name;}
    bool inStock(){return this->stockAvailable;}

    void fillStock(int stock){
        this->stockCount += stock;
    }
};

class NotificationRequest{
public:
    int id;
    int userId;
    int productId;
    string status; // pending ignored rejected 
    string channel;  // Sms  email  phone 
    time_t createdAt;
    time_t updatedAt;
};

class Database{
private:
    static Database *db;
    Database(){}
public:
    map<int , User>userById; // O(logn)
    map<int , Products>productById;
    map<int , NotificationRequest>requestById;

    void addUser(User user){
        this->userById[user.getId()] = user;
    }

    void addProduct(Products product){
        this->productById[product.getId()] = product;
    }

    void addNotification(int notificationId , string wayToNotify , User user , Products product){
        NotificationRequest notify;
        notify.id = notificationId;
        notify.userId = user.getId();
        notify.channel = wayToNotify;
        notify.createdAt = chrono::system_clock::to_time_t(chrono::system_clock::now());
        notify.updatedAt = chrono::system_clock::to_time_t(chrono::system_clock::now());
        notify.productId = product.getId();
        notify.status = "Pending";
        this->requestById[notificationId] = notify;
    }

    static Database *getInstance(){
        if(!db or db == NULL){
            // Mutex Lock
            db = new Database();
            // Mutex Unlock
        }
        return db;
    }

    vector<int>getPendingRequest(int productId){
        vector<int>notifications;
        for(auto &entry : this->requestById){
            int requestId = entry.first;
            NotificationRequest &notify = entry.second;

            if(notify.status == "Pending" and notify.productId == productId){
                notifications.push_back(requestId);
            }
        }
        return notifications;
    }

    vector<int> getAllRequest(){
        vector<int>notifications;
        for(auto &entry : this->requestById){
            int requestId = entry.first;
            NotificationRequest &notify = entry.second;
            notifications.push_back(requestId);
        }
        return notifications;
    }

    void batchProcessing(int batchSize = 50 , int timeToSleep = 5){
        vector<int>notifications;
        int currentRequest = 0;

        for(auto &entry: this->requestById){
            int requestId = entry.first;
            NotificationRequest &notify = entry.second;

            if(notify.status == "Pending"){
                notifications.push_back(requestId);
                currentRequest++;

                if(currentRequest == batchSize){
                    currentRequest = 0;
                    notifications.clear();
                    Sleep(timeToSleep*1000);
                }
            }
        }
    }

    void updateStatus(int requestId , string status = "Success"){
        this->requestById[requestId].status = status;
    }
}; Database *Database::db = NULL;

class NotificationStrategy{
public:
    virtual void notifyUser(NotificationRequest notify) = 0;
    virtual ~NotificationStrategy() = default;
};

class EmailNotification : public NotificationStrategy{
public:
    void notifyUser(NotificationRequest notify) override{
        Database *d1 = Database::getInstance();
        string userName = d1->userById[notify.userId].getName();

        string email = d1->userById[notify.userId].getEmail();
        bool isActive = d1->userById[notify.userId].isActiveUser();
        string productName = d1->productById[notify.productId].getName();
        int productId = d1->productById[notify.productId].getId();

        if(isActive && email.length() > 0 && productName.length() > 0 && productId != 0){
            cout<<"Email Sent To "<<email<<" Regarding Product "<<productName<<" Is Now in Stock \n";
        }else{
            cout<<"No Email Service is Found Error 501 \n";
        }
    }
};

class PushNotification : public NotificationStrategy{
public:
    void notifyUser(NotificationRequest notify) override{
        Database *d1 = Database::getInstance();
        string userName = d1->userById[notify.userId].getName();

        string email = d1->userById[notify.userId].getEmail();
        bool isActive = d1->userById[notify.userId].isActiveUser();
        string productName = d1->productById[notify.productId].getName();
        int productId = d1->productById[notify.productId].getId();

        if(isActive && email.length() && productName.length() && productId){
            cout<<"Push Notification Sent To "<<userName<<" Regarding Product "<<productName<<" Is Not in Stock \n";
        }else{
            cout<<"No Push Notification Service is Found Error 501 \n";
        }
    }
};

class SMSNotification : public NotificationStrategy{
public:
    void notifyUser(NotificationRequest notify) override{
        Database *d1 = Database::getInstance();
        string userName = d1->userById[notify.userId].getName();

        string email = d1->userById[notify.userId].getEmail();
        bool isActive = d1->userById[notify.userId].isActiveUser();
        string productName = d1->productById[notify.productId].getName();
        int productId = d1->productById[notify.productId].getId();

        if(isActive && email.length() && productName.length() && productId){
            cout<<"SMS Notification Sent To "<<userName<<" Regarding Product "<<productName<<" Is Not in Stock \n";
        }else{
            cout<<"No SMS Notification Service Found Error 501 \n";
        }
    }
};

class WhatsAppNotification : public NotificationStrategy{
public:
    void notifyUser(NotificationRequest notify) override{
        Database *d1 = Database::getInstance();
        string userName = d1->userById[notify.userId].getName();

        string email = d1->userById[notify.userId].getEmail();
        bool isActive = d1->userById[notify.userId].isActiveUser();
        string productName = d1->productById[notify.productId].getName();
        int productId = d1->productById[notify.productId].getId();

        if(isActive && email.length() && productName.length() && productId){
            cout<<"WhatsApp Notification Sent To "<<userName<<" Regarding Product "<<productName<<" Is Not in Stock \n";
        }else{
            cout<<"No WhatsApp Notification Service Found Error 501 \n";
        }
    }
};

class ProcessNotification{
private:
    static ProcessNotification *process;
    ProcessNotification(){}
public:
    void processNotification(vector<int>notifications){

        Database *d1 = Database::getInstance();
        unique_ptr<EmailNotification>email = make_unique<EmailNotification>();
        unique_ptr<SMSNotification>sms = make_unique<SMSNotification>();
        unique_ptr<PushNotification>push = make_unique<PushNotification>();
        unique_ptr<WhatsAppNotification>whatsapp = make_unique<WhatsAppNotification>();

        for(auto notify : notifications){
            string channel = d1->requestById[notify].channel;
            if(channel == "Email"){
                email->notifyUser(d1->requestById[notify]);
            }
            else if(channel == "Push"){
                push->notifyUser(d1->requestById[notify]);
            }
            else if(channel == "SMS"){
                sms->notifyUser(d1->requestById[notify]);
            }
            else if(channel == "Whatsapp"){
                whatsapp->notifyUser(d1->requestById[notify]);
            }
            else{
                throw runtime_error("Illegal Argument!!");
            }
            d1->updateStatus(notify , "Success");
        }
    }
    static ProcessNotification *getInstance(){
        if(!process or process == NULL){
            process = new ProcessNotification();
        }
        return process;
    }

    void processPendingRequest(int productId){
        Database *d1 = Database::getInstance();
        vector<int>notifications = d1->getPendingRequest(productId);
        processNotification(notifications);
    }

    void processAllRequest(){
        Database *d1 = Database::getInstance();
        vector<int>notifications = d1->getAllRequest();
        processNotification(notifications);
    }

    void processBatch(int batchSize = 50 , int timeToSleep = 5){
        Database *d1 = Database::getInstance();
        d1->batchProcessing(batchSize , timeToSleep);
    }

}; ProcessNotification *ProcessNotification::process = NULL;

int main(){
    Database *d1 = Database::getInstance();
    User user1 = User(10 , "Aaju" , "aaju@go.srdev.com" , true , "123123");
    User user2 = User(11 , "Tanuj" , "tanuj@node.dev.com" , true , "234234");
    User user3 = User(12 , "karan" , "karan@python.dev.com" , true , "567567");
    User user4 = User(13 , "Mehak" , "Mehak@java.srdev.com" , true , "234234");

    Products p1 = Products(10 , 3 , "Face Washes" , true);
    Products p2 = Products(11 , 5 , "Serums" , true);
    Products p3 = Products(12 , 6 , "Moisturizers" , true);
    Products p4 = Products(13 , 2 , "Sunscreens" , true);
    Products p5 = Products(14 , 0 , "Coffee Face Mask Caffeine" , false);

    d1->addUser(user1);
    d1->addUser(user2);
    d1->addUser(user3);
    d1->addUser(user4);

    d1->addProduct(p1);
    d1->addProduct(p2);
    d1->addProduct(p3);
    d1->addProduct(p4);
    d1->addProduct(p5);

    d1->addNotification(23 , "SMS" , user1 , p5);
    d1->addNotification(24 , "Push" , user2 , p5);
    d1->addNotification(25 , "Whatsapp" , user3 , p5);
    d1->addNotification(26 , "Email" , user4 , p5);

    ProcessNotification *process = ProcessNotification::getInstance();
    process->processPendingRequest(14);
}