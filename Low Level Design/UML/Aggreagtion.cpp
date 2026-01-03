// Aggregation association means that one object hold the multiple object inside it for exmaple
// a room can hold the chai , sofa , bed inside it show an aggregation association
// But it does not owns them means sofa , chai , bed are independent with Room Object
// Room Cannot delete sofa

#include <bits/stdc++.h>
using namespace std;

class Sofa{
public:
    void sit(){
        cout<<"You can sit on sofa"<<endl;
    }
};

class Bed{
public:
    void sit(){cout<<"You can rest on Bed"<<endl;}
};

class Room{
private:
    Sofa *sofa;
    Bed *bed;
public:
    Room(Sofa *sofa , Bed *bed):bed(bed) , sofa(sofa){}
    void useRoom(){
        this->sofa->sit() , this->bed->sit();
    }

    ~Room(){}
};

int main()
{
    Sofa *sofa = new Sofa();
    Bed *bed = new Bed();

    Room *room = new Room(sofa , bed);
    room->useRoom();

    delete room;
    sofa->sit();
    bed->sit();

    delete sofa;
    delete bed;
}