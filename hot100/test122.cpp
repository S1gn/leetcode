#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxp = 0;
       for(int i=0; i<prices.size() - 1; i++)
       {
            if(prices[i + 1] > prices[i])
                maxp += prices[i + 1] - prices[i];
       }
       return maxp;
    }
};
int main() {
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<solution.maxProfit(prices);
    return 0;
}

/*
有时间写写二维动态规划
*/