// Single Responsiblity principle says that every class should work only for he ONE task it should not do the multiple task for exmaple
// A TV remote should be only used for the TV as well but if it is used to manage the AC & Fridge leads to an big issue 
// A changing or updateing the particualr function leads to change to other task simply means that one function chnage will reflect to another as well

#include <bits/stdc++.h>
using namespace std;

class Product{
private:
    string name;
    double price;
public:

    Product(string name , double price) : name(name) , price(price){}
    double getPrice(){return this->price;}
    string getName(){return this->name;}

    Product *getProduct(){
        return this;
    }
};

class ShoppingCart{
private:
    vector<Product*>products;
public:
    void addProduct(Product *p){
        products.push_back(p);
    }

    const vector<Product*>&getProduct(){
        return this->products;
    }

    double calculateTotalPrice(){
        double total = 0.0;
        for(auto &product : products){
            total += product->getPrice();
        }
        return total;
    }
};

class ShoppingCartPrinter{
private:
    ShoppingCart *cart;
public:
    ShoppingCartPrinter(ShoppingCart *sc){
        this->cart = sc;
    }

    void printInvoice(){
        cout<<" Shopping Cart Invoice \n";
        for(auto p : cart->getProduct()){
            cout<<p->getName() <<" "<<p->getPrice()<<" \n";
        }
        cout<<"Total Price is "<<cart->calculateTotalPrice()<<"\n";
    }
};

class ShoppingCartStorage{
private:
    ShoppingCart *cart;
public:
    ShoppingCartStorage(ShoppingCart *sc){this->cart = sc;}
    void saveToDB(){
        cout<<"Saving To DB \n";
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop" , 56000));
    cart->addProduct(new Product("TV" , 54000));

    ShoppingCartPrinter *print = new ShoppingCartPrinter(cart);
    print->printInvoice();

    ShoppingCartStorage *store = new ShoppingCartStorage(cart);
    store->saveToDB();

}