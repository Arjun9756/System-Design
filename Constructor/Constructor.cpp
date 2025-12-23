#include <bits/stdc++.h>
using namespace std;

/**
 * Constructor an special member function whose name is same like class name which is used to provide the pre value to the object it does not have return type
 * Is is needed so that object does not have garbage values inner it Object is created when constructor runs not to say that constructor runs when object created
 * its totaly wrong
 * 
 *  We Have 3 Types of Constructor
 *  A. Default Constructor Created By Compiler When No Explicit Constructor is Created
 *  B. Parameterised Constructor Which Takes @param a inner it
 *  C. Copy Constructor Which Accepts an Object Inner it
 *  Drill Note Copy Constructor has 2 variant deep copy and shallow copy deepy copy means shallow copy means only outer obj is copied but inner one has refecnece
 * but in deep copy both has copy only
 */

 /**
  * Common Ques 
  * 1. Is Constructor Can Be Private If Yes So Whats The Actual Need And Why To Do So ?? If Possible Use First Thought Principle No Direct Answer
  * 2. Constructor Overloading is Possible ?? Whats the Need
  * 
  * Answer 1. Yes Constructor can be private but as soon as we create the constructor  private we are not are to create the objects this is used to create the singleton class
  *           A class which has only one and only one object still ques arises that why there is the need of private constructor or signleton class
  *           Lets think your system has to connect with database okay not let say you have implement a class DBCOnnect which has direct logic to connect with Database
  *           Now we also know that this class can have multiple objects that's the real problem think of that whenever you are creating the db object a network call
  *           will be made to connect with db and connecting with database takes a lot of resourse , netwrok bandwith , latency also database is always present on another
  *           continent so that it will also increase the connection time 
  *           Now can you bear out this cost not an all beacuse in local you have now problem but when your app is in production for every call , latency , bandwith,
  *           your service active time you have to pay for the same which increase your bill which directly impacts to business profit 
  *         
  *         Solution if somehow we are able to manage that only one object will be cretaed and if developer tries to create another one not an issue return the 
  *         refernce of object that firstly created.
  */

class Constructor{
public:
    // Default Constructor
    Constructor(){
        cout<<"Constructor Without Param \n";
    }  

    Constructor(int a){
        cout<<"Constructor With One Param \n";
    }

    Constructor(Constructor *cons){
        cout<<"Copy Constructor \n"; 
    }

    Constructor(int a , int b){
        cout<<"Yes Constructor Overloading is Allowed! \n";
    }
};

int main()
{
    Constructor *c1 = new Constructor();
    Constructor *c2 = new Constructor(2);
    Constructor *c3 = new Constructor(c2);
}