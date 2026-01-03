#include <bits/stdc++.h>
using namespace std;

/* 

Encapsulation is basically a mechnaism in which all the data are stored into a single unit and provide only essential dertails and 
it says about the data security as well  and restrict Outside Objext to not to aceess the private memeber

For exmaple lets say An employee in a XYZ company its all details PAN Card , Adhar Card , Salary Slip will be stored into a single unit
but only non essential details are not being stored for the data secrutiy like Name , DOB , Blood group 

*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string panCard;
    string aadharCard;
    double salary;

public:

    Employee(string pan, string aadhar, double sal) {
        panCard = pan;
        aadharCard = aadhar;
        salary = sal;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double newSalary) {
        if (newSalary > 0) {
            salary = newSalary;
        } else {
            cout << "Invalid salary amount." << endl;
        }
    }

    void displayInfo() const {
        cout << "PAN: [Protected]" << endl;
        cout << "Aadhar: [Protected]" << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee emp("ABCDE1234F", "123456789012", 50000.00);

    cout << "Current Salary: " << emp.getSalary() << endl;

    emp.setSalary(60000.00);
    cout << "Updated Salary: " << emp.getSalary() << endl;

    emp.displayInfo();

    return 0;
}