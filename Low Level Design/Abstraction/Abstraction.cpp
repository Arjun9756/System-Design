/**
 * Abstraction basically means that showing only the necessary details without including the background details 
 * for exmaple whenever you click on call button on mobile your call is started but the network connection , audio fragmentation is totaly abstracted from you
 * Same when you perform the sorting on data using internal sorting mehtods it short out the data but you doesn't know about the alogrithm of the same
 * 
 * Abstraction takes the help of the encapsulation for providing the nescessary details
 * Abtraction is a concept that state down that what to show the client but encapsulation is a technique to hide the data from direct modification
 */

#include <bits/stdc++.h>
using namespace std;

class Abstract{
private:
    double solveSqrt(int num)
    {
        int left = 1 , right = num;
        double ans = 0.0;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            double square = static_cast<double>(mid) * static_cast<double>(mid);
            double number = static_cast<double>(num);

            if(square == number){
                return static_cast<double>(mid);
            }
            else if(square < number){
                ans = static_cast<double>(mid);
                left = mid+1;
            }
            else
                right = mid-1;
        }
        return ans;
    }
public:
    inline double getSqrt(int num){
        return solveSqrt(num);
    }
};

int main()
{
    Abstract *a1 = new Abstract();
    cout<<a1->getSqrt(6);
}