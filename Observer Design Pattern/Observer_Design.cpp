// Observer design pattern ek esa design pattern hota h jha per ek observer subject ki state ya situation ko sense ya observer 
// kar rha hota h uske chnage hone per apni taraf se koi action le rha hota h
// Exmaple jese ek news app jab bhi koi news publish krti h toh humko notification mil jati h 
// ab is notification ko pane ke 2 tarike h ya toh hum polling karle observer se 
// ya subject khud notify krega observer ko ek ek karke

#include <bits/stdc++.h>
using namespace std;

class User;

class YoutubeChannel{
public:
    virtual void addSubscriber(User *user) = 0;
    virtual void removeSubscriber(User *user) = 0;
    virtual void notify() = 0;
    virtual void uploadVideo(const string& title, const string& link) = 0;
    virtual ~YoutubeChannel(){}
};

class User{
public:
    virtual void update(const string& videoTitle, const string& videoLink) = 0;
    virtual ~User() {}
};

class MyChannel : public YoutubeChannel{
private:
    vector<User*>user;
    string channelName;
    string videoLink;
    string currentVideoTitle;
public:
    MyChannel(string name) {
        this->channelName = name;
    }

    void addSubscriber(User *user)override{
        this->user.push_back(user);
    }

    void removeSubscriber(User *user)override{
        this->user.erase(remove(this->user.begin(), this->user.end(), user), this->user.end());
    }

    void uploadVideo(const string &title , const string &link)override{
        this->videoLink = link;
        this->currentVideoTitle = title;

        notify();
    }

    void notify() override {
        for (auto subscriber : this->user) {
            subscriber->update(currentVideoTitle, this->videoLink);
        }
    }
};

class ConcreteUser : public User {
private:
    string userName;

public:
    ConcreteUser(string name) {
        this->userName = name;
    }

    void update(const string& videoTitle, const string& videoLink) override {
        cout<<"Got an New Video Notify Video title : "<<videoTitle<<" Video link is : "<<videoLink<<endl;
    }
};

int main()
{
    MyChannel *techChannel = new MyChannel("CodeWithArjun");
    ConcreteUser *u1 = new ConcreteUser("Rohit");
    ConcreteUser *u2 = new ConcreteUser("Priya");

    techChannel->addSubscriber(u1);
    techChannel->addSubscriber(u2);

    techChannel->uploadVideo("Observer Pattern in C++", "http://youtube.com/v/observer");
    techChannel->removeSubscriber(u2);

     techChannel->uploadVideo("Strategy Pattern Explained", "http://youtube.com/v/strategy");

    delete techChannel;
    delete u1;
    delete u2;

    return 0;
}