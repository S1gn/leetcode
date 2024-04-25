#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        auto a = vector<int> (amount + 1);
        a[0] = 0;
        for(int i = 1; i<=amount; i++)
        {
            int minnum = INT32_MAX;
            for(int j = 0; j<coins.size(); j++)
                if((i - coins[j]) < 0)
                    minnum = min(minnum, INT32_MAX);
                else
                    minnum = min(minnum, a[i - coins[j]]);
            
            if(minnum == INT32_MAX)
                a[i] = INT32_MAX;
            else 
                a[i] = minnum + 1;
            cout<<a[i]<<endl;
        }
        if(a[amount] == INT32_MAX) return -1;
        return a[amount];
    }
};
int main() {
    Solution solution;
    vector<int> coins = {1};
    cout<<solution.coinChange(coins, 0);
    return 0;
}