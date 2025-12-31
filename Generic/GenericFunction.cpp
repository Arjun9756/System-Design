#include <bits/stdc++.h>
using namespace std;

template<typename T , typename U>
T add(T a , U b ){
    return a + b;
}

int main()
{ 
    cout<<add(4,2.3)<<endl; // 6   beacuse return type if T first num of parameter int
    cout<<add(2.3,4); // 6.3   // beacuse return type if T first num of paramter is now double
}