#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int>(4));
        // 买 卖 二买 二卖
        dp[0] = {-prices[0], 0, -prices[0], 0};
        for(int i = 1; i<n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], prices[i] + dp[i - 1][2]);
        }
        return dp[n - 1][3];
    }

    
};
int main() {
    Solution solution;
    vector<int> a = {3,3,5,0,0,3,1,4};
    cout<<solution.maxProfit(a);
    return 0;
}