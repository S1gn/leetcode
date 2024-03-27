#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(true)
        {
            fast = sumhappy(fast);
            if(fast == 1)
                return true;
            if(fast == slow)
                return false;
            fast = sumhappy(fast);
            if(fast == 1)
                return true;
            if(fast == slow)
                return false;
            slow = sumhappy(slow);
        }
    }
    
    int sumhappy(int n)
    {
        int sum = 0;
        while(n!=0)
        {
            sum = sum + (n % 10) * (n % 10);
            n = n/10;
        }
        return sum;
    }
};
int main() {
    Solution solution;
    cout<<solution.isHappy(19);
    return 0;
}