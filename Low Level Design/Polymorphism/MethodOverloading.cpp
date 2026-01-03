/**
 * Method Overloading is the compile time concept of the polymorphism which means that a function with same name but different argument
 * difference between the argument can be of no of argumnent , order of argumnet , type of argumnet
 * 
 * Why there is the need of method overloading
 * Let say we have to connect database if we provide the host and port then it should connect with system or current database if we provide
 * URI like mongodb it should connect with same
 */

#include <bits/stdc++.h>
using namespace std;

class DatabaseConnect{
public:
    void connect(){
        cout<<"Connecting to Database....\n";
    }

    void connectDB(const string host , const int port){
        cout<<"Connecting to LocalHost Database.... 127.0.0.1 Connected \n";
    }

    void connectDB(const string URI){
        cout<<"Connecting With MySQl || MongoDB Database.....\n";
    }

    ~DatabaseConnect(){}
};

int main()
{
    DatabaseConnect *d1 = new DatabaseConnect();
    d1->connectDB("localhost" , 3306);
    d1->connectDB("+mongodb+srvcgjihewio");

    delete d1;
}