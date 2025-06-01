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

class Persistence{
private:
    
public:
    virtual void save(ShoppingCart *cart) = 0;
    void show(){
        cout<<"Hello world";
    }
};

class SQLPersistence : public Persistence{
public:
    void save(ShoppingCart *cart){
        for(auto s : cart->getProduct()){
            // SaveToSQL()
        }
        cout<<"Saved to SQL \n";
    }
};

class MongoPersistence : public Persistence{
public:
    void save(ShoppingCart *cart){
        for(auto s : cart->getProduct()){
            // SaveToMongoDB()
        }
        cout<<"Saved to Mongo \n";
    }
};

class FilePersistence : public Persistence{
public:
    void save(ShoppingCart *cart){
        for(auto s : cart->getProduct()){
            // SaveToFile()
        }
        cout<<"Saved to File \n";
    }
};


int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop" , 56000));
    cart->addProduct(new Product("TV" , 51000));

    ShoppingCartPrinter *invoice = new ShoppingCartPrinter(cart);
    invoice->printInvoice();

    SQLPersistence *sql = new SQLPersistence();
    MongoPersistence *mongo = new MongoPersistence();
    FilePersistence *file = new FilePersistence();

    sql->save(cart) , mongo->save(cart) , file->save(cart);
}