#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        else 
            return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
int main() {
    Solution solution;
    cout<<solution.climbStairs(4);
    return 0;
}