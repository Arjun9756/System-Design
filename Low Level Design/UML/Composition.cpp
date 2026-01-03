// Composition means that One object is created with the help of multiple object if that object get destroyed everyone will be destroyed
// Exmaple a room ceated sofa & chair ir roo mis destroyed every object inside room will be destroyed
#include <bits/stdc++.h>
using namespace std;

class Sofa{
public:
    void sit(){cout<<"You can sit on sofa"<<endl;}
    ~Sofa() {
        cout << "Sofa destroyed.\n";
    }
};

class Bed{
public:
    void rest(){cout<<"You can rest on bed"<<endl;}
    ~Bed() {
        cout << "Bed destroyed.\n";
    }
};

class Room{

private:
    Sofa s1;
    Bed b1;

public:
    Room(){
        cout<<"Room is Already Created"<<endl;
    }

    ~Room(){
        cout<<"Room is Destroyed \n";
    }

    void userRoom(){
        s1.sit();
        b1.rest();
    }
};

int main()
{
    Room r1;
    r1.userRoom();

    return 0;
}