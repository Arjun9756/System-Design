#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "User.h"
using namespace std;

class Database {
private:
    static Database* instance;
    Database() {} // private constructor

public:
    static Database* getInstance() {
        if (!instance)
            instance = new Database();
        return instance;
    }

    void saveToDB(User* user, const string& content, const string& service) {
        // For demonstration, just print to console
        cout << "[DB] Notification saved for user: " << user->getName()
             << ", Service: " << service
             << ", Content: " << content << endl;
    }
};

// Initialize static member
Database* Database::instance = nullptr;

#endif