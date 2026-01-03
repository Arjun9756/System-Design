// Method Argumnet or Signature states that jo class apne base class se inherit ho rhi h wo apne method ka signature same rkhe as same as 
// parent class means => parameter , return type , name of method all should be same as base class

#include <bits/stdc++.h>
using namespace std;

class Parent{
public:
    virtual void printMsg(string msg){
        cout<<msg<<endl;
    }
};

class Child : public Parent{
public:
    void printMsg(string msg){
        cout<<msg<<endl;
    }
};

int main(){
    Child *c1 = new Child();
    c1->printMsg("Arjun Singh Negi");
}