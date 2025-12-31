/**
 * In C++ we have 3 access modifier public private and protected 
 * public basically means that value can be directly access with the help of object no need to go through with a function a public function can be access outside the 
 * package as well
 * 
 * private means that value of function can onyl be accessible within the same class not outsider is allowed even though no direct access with object as well
 * intermidiary public function is required
 * 
 * protected basically means value can only be accessible within the same class or child one even though direct access with object also not allowed
 */

#include <bits/stdc++.h>
using namespace std;

class AccessModifier{
private:
    int privateValue;
protected:
    int protectedValue;
public:
    int publicValue;
};

int main()
{
    AccessModifier *a1 = new AccessModifier();
    a1->publicValue = 90; // allowed
    a1->protectedValue = 32; // not allowed
    a->privateValue = 77;        // not allowed
}