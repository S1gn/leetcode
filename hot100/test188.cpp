#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int>(k * 2));
        // 买 卖 二买 二卖
        for(int i = 0; i < 2 * k; i++)
        {
            dp[0][i] = i % 2 ? 0 : -prices[0];
        }
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            for(int j = 1; j < k; j++)
            {
                dp[i][j * 2 - 1] = max(dp[i - 1][j * 2 - 1], prices[i] + dp[i - 1][j * 2 - 2]);
                dp[i][j * 2 ] = max(dp[i - 1][j * 2], -prices[i] + dp[i - 1][j * 2 - 1]);
            }
            dp[i][2 * k - 1] = max(dp[i - 1][2 * k - 1], prices[i] + dp[i - 1][2 * k - 2]);
        }
        return dp[n - 1][2 * k - 1];
    }

    
};
int main() {
    Solution solution;
    vector<int> a = {3,2,6,5,0,3};
    cout<<solution.maxProfit(2, a);
    return 0;
}