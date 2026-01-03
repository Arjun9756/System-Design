/**
 * Template is basically a fetaure of a c++ which helps us to acheive the generic programming
 * Generic programming basically means that a function or a class can accept the any the input with it 
 * This process helps us that we only have to write the algorithm and the logic and rest of the computation and conversion will be done by system itself
 * 
 * We can define the template by 2 ways
 * template<typename T>
 * template<class T , class V> // T & V Means no of input
 * 
 * How Does it actually works whenever you create out the template so at the time of compilation process the compiler creates the copy of that function with 
 * different permutation and combination of data type
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>

class Demo{
private:
    T value1;
public:
    T getMax(T val1 , T val2){
        return (val1 > val2 ? val1 : val2);
    }
};

int main()
{
    Demo<int> *d = new Demo<int>();
    cout<<d->getMax(5 , 9);

    delete d;
}