#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        int flag = 1;
        if(dividend > 0) {dividend = - dividend; flag = -flag;}
        if(divisor > 0){divisor = -divisor; flag= -flag;}
        while(dividend<=0)
        {
            dividend = dividend - divisor;
            result++;
            if(result>=2147483647){
                if(flag=1)return 2147483647;
                else
                    if(dividend<0) return -2147483648;
                    else return -2147483647;
            }
        }
        return flag*(result-1);
    }
};
int main() {
    Solution solution;
    cout<<solution.divide(2147483647, -2147483648);
    return 0;
}