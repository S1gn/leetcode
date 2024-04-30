#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(matrix[i][j] == '0')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                        if(1 > res) res = 1;
                    }
                    else
                    {
                        dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                        res = max(res, dp[i][j]);
                    }
                }
            }
        }
        return res * res;
    }
};
int main() {
    Solution solution;
    return 0;
}