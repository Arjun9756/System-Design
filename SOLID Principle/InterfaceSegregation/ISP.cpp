/**
 * Interface segregation priciple state down that the client should not be forefully provided those features or function which he never going to use it
 * For exmaple if we provide the speaker in every car so it will break the interface segregation pricniple beacuse it may possible that some of the cars
 * will not contain the speaker
 * 
 * Same exmaple like Elastic Search should does not have the need of user class it should be avoided
 * One thing that interface is just a contract that whats it will contains that's all nothing more it can be onyl acheivale in c++ with pure virtual function or abstract class
 * and virtual destructor 
 */

#include <bits/stdc++.h>
using namespace std;

class UserManagement{
public:
    virtual void addUser(string name , string email , string pass) = 0;
    virtual void deleteUser(string email) = 0;
};

class ElasticSearch{
public:
    virtual void indexDocument(int documentId) = 0;
    virtual void findDocument(string regex) = 0;
    virtual ~ElasticSearch(){
        cout<<"Elastic Search Destructor \n";
    }
};

class Search : public ElasticSearch{
public:
    void indexDocument(int documentId) override{
        cout<<"Index Document \n";
    }
    void findDocument(string regex) override{
        cout<<"This is Document \n";
    }
    ~Search(){
        cout<<"Search Destructor \n";
    }
};

int main()
{
    Search *s1 = new Search();
    s1->indexDocument(2);
    s1->findDocument("abc");
}