#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     auto dp = vector<int> (nums.size());
    //     dp[0] = 1;
    //     int res = 0;
    //     for(int i = 1; i<nums.size(); i++)
    //     {
    //         int temp = INT32_MIN;
    //         for(int j = 0; j<i; j++)
    //         {
    //             if(nums[i] > nums[j])
    //                 temp = max(temp, dp[j]);
    //         }
    //         if(temp == INT32_MIN)
    //             temp = 0;
    //         dp[i] = temp + 1;
    //         res = max(dp[i], res);
    //     }
    //     return res;
    // }
    int lengthOfLIS(vector<int>& nums){
        vector<int> minlist;
        if(nums.size() == 0) return 0;
        minlist.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] > minlist[minlist.size() - 1])
                minlist.push_back(nums[i]);
            else
                for(int j = 0; j<minlist.size() - 1; j++)
                    if(minlist[j] > nums[i])
                    {
                        minlist[j] = nums[i];
                        break;
                    }
            cout<<minlist.size()<<endl;
        }
        return minlist.size();
    }
};
int main() {
    Solution solution;
    vector<int> coins = {4,10,4,3,8,9};
    cout<<solution.lengthOfLIS(coins);
    return 0;
}