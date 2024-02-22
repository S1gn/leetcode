#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max;
        max.push_back(0);
        int profit = 0;
        int maxp = 0;
        for(int i=1; i<prices.size(); i++)
        {
            profit = max[i - 1] + prices[i] - prices[i - 1];
            if(profit>0)
                max.push_back(profit);
            else
                max.push_back(0);
            if(profit>maxp)
                maxp = profit;
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