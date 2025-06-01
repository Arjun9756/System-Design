//Open close principle says that any class should be open for the extension but close for the modification
// which means that we cannout update or out existing code instead of that we can add some new to them
// Example Saving to DB is before a single class but we can extend it using abstraction & inheritance to saveToSQL() , saveToMongo()

#include <bits/stdc++.h>
using namespace std;

class Product{
public:
    string name;
    double price;

    Product(string name , double price):name(name) , price(price){}
};

class ShoppingCart{
private:
    vector<Product*>products;
public:
    void addProduct(Product *p){
        products.push_back(p);
    }

    const vector<Product*>&getProduct(){return this->products;}
    double calculatePrice(){
        double total = 0.0;
        for(auto p : products){
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
private:
    ShoppingCart *cart;
public:
    ShoppingCartPrinter(ShoppingCart *cart){
        this->cart = cart;
    }

    void printInvoice(){
        for(auto s : cart->getProduct()){
            cout<<s->name<<" "<<s->price<<endl;
        }
        cout<<"Total Bill is "<<cart->calculatePrice()<<endl;
    }
};

class ShoppingCartStorage{
private:
    ShoppingCart *cart;
public:

    ShoppingCartStorage(ShoppingCart *cart){this->cart = cart;}
    void saveToSQLDatabase(){
        for(auto data : cart->getProduct()){
            // SaveToSQL()
        }
    }

    void saveToMongoDB(){
        for(auto data : cart->getProduct()){
            // SaveToMongo()
        }
    }

    void saveToFile(){
        for(auto data : cart->getProduct()){
            // SaveToFile()
        }
    }

};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop" , 56000));
    cart->addProduct(new Product("TV" , 51000));

    ShoppingCartPrinter *invoice = new ShoppingCartPrinter(cart);
    invoice->printInvoice();

    ShoppingCartStorage *db = new ShoppingCartStorage(cart);
    db->saveToSQLDatabase();
    db->saveToMongoDB();
    db->saveToFile();
}