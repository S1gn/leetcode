#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
            return 1/quickpow(x, -n);
        else
            return quickpow(x, n);
    }
    double quickpow(double x, int n)
    {
        if(n == 1)
            return x;
        if(n == 0)
            return 1;
        if(n % 2 == 0)
        {
            double temp = myPow(x, n/2);
            return temp * temp;
        }
        else
        {
            double temp = myPow(x, n/2);
            return temp * temp * x;
        }
        
    }
};
int main() {
    Solution solution;
    return 0;
}