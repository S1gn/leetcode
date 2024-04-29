#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n  = s.length();
        int start = 0;
        int end = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        char temp = s[0];
        for(int i = 1; i < n; i++)
        {
            if(s[i] == temp)
            {
                dp[i][i - 1] = 1;
                start = i - 1;
                end = i;
            }
                
            temp = s[i];
        }
        
        
        for(int i = 1; i< n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if((i - j) < 2 || dp[i][j] == 1)
                    continue;
                else
                {
                    if(s[i] == s[j] && dp[i - 1][j + 1] == 1)
                    {
                        dp[i][j] = 1;
                        if((i - j) > (end - start))
                        {
                            start = j;
                            end = i;
                        }
                    }
                    else
                        dp[i][j] = 0;
                }
            }
        }
        // for(int i = 0; i<n; i++)
        // {
        //     for(int j = 0; j<n; j++)
        //         cout<<dp[i][j];
        //     cout<<endl;
        // }
        // cout<<start<<end<<endl;
        return s.substr(start, end - start + 1);

    }
};
int main() {
    Solution solution;
    cout<<solution.longestPalindrome("ababa");
    return 0;
}