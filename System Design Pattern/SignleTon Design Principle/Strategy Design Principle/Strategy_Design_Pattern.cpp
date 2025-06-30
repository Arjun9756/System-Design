// System design pattern can be considered a technique or trick which help us to design the system in best and optimal way

#include <bits/stdc++.h>
using namespace std;

class Talkable{
public:
    virtual void talk(string word) = 0;
    ~Talkable(){}
};

class Walkable{
public:
    virtual void walk() = 0;
    ~Walkable(){}
};

class flyable{
public:
    virtual void fly() = 0;
    ~flyable(){}
};

class NormalTalk:public Talkable{
public:
    void talk(string word){
        cout<<"Speaking word : "<<word<<endl;
    }
};

class NoTalk:public Talkable{
public:
    void talk(string word){
        cout<<"No talk : "<<endl;
    }
};

class NormalWalk:public Walkable{
public: 
    void walk(){
        cout<<"Walking -- "<<endl;
    }
};

class NoWalk:public Walkable{
public:
    void walk(){
        cout<<"No walk --"<<endl;
    }
};

class NormalFly:public flyable{
public:
    void fly(){
        cout<<"Flying with behavoir"<<endl;
    }
};

class NoFly:public flyable{
public:
    void fly(){
        cout<<"Not able to fly : "<<endl;
    }
};

class Robot{
private:
    Talkable *t;
    Walkable *w;
    flyable *f;
public:
    Robot(Talkable *t , Walkable *w , flyable *f):t(t) , f(f) , w(w) {}
    void walk(){
        this->w->walk();
    }
    void talk(string word){
        this->t->talk(word);
    }
    void fly(){
        this->f->fly();
    }
};

int main()
{   
    Robot *r1 = new Robot(new NormalTalk , new NormalWalk , new NoFly);
    r1->fly();
    r1->talk("Hello world");
    r1->walk();

}