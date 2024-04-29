#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if(m + n != s3.length())
            return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = 1;
        for(int i = 0; i<=m; i++)
        {
            for(int j = 0; j<=n; j++)
            {
                if(s3[i + j - 1] == s1[i - 1] && i > 0)
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if(s3[i + j - 1] == s2[j - 1] && j > 0)
                {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    Solution solution;
    cout<<solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
}