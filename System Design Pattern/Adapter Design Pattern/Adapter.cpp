// Adapter design pattern ek esa pattern hota h jo kisi third party library ko hmare code ke sath without
// any our code modification humko help krta h taki hum third party ke sath Communicate kar ske 

// Exmpale se Humko Apni video ke liye title ke basis pe tags generate krne h 
// or ye kam hum third party se kran chate h ab agr hum wo library ko direct apne code
// me rkehnge toh Ise OCP prinicple break hoga kyuki future me agr change krna pda toh

// Isliye hum yha per ek adapter class lgynge jo hmare code ko smj kar third party library se communicate krega

// Abhi hum Clietn se data ko JSON me convert ka Adapter Use krenge
#include <bits/stdc++.h>
using namespace std;

class XMLDataProvider{
private:
    string data;
public:
    XMLDataProvider(){}
    string getXMLData(string data){
        this->data = "<xml>" + data + "</xml>";
        return this->data;     // Assuming Yha Per Data Convert Ho Jyga
    }
};

class IReports{
public:
    virtual string getJSONData(string data) = 0;
    virtual ~IReports(){}
};

class Adapter : public IReports{
private:
    XMLDataProvider *xml;    
public:
    Adapter(XMLDataProvider *xml){
        this->xml = xml;
    }

    string getJSONData(string data) override {
        string xmlData = xml->getXMLData(data);
        string jsonData = "{ \"data\": \"" + data + "\" }";
        return jsonData;
    }
};

int main()
{
    XMLDataProvider *xmlProvider = new XMLDataProvider();
    IReports *report = new Adapter(xmlProvider);

    string title = "Design Pattern in C++";
    cout << "Client Got JSON Data: " << report->getJSONData(title) << endl;
}