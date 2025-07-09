#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string name;
    string phone;
    string email; 

public:
    User(const string& name, const string& phone, const string& email = "")
        : name(name), phone(phone), email(email) {}

    // Getters
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }

    // Setters (अगर जरूरत हो)
    void setName(const string& n) { name = n; }
    void setPhone(const string& p) { phone = p; }
    void setEmail(const string& e) { email = e; }
};

#endif