#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> maxnum;
        maxnum.push_back(nums[0]);
        maxnum.push_back(max(nums[0], nums[1]));
        for(int i = 2; i < nums.size(); i++)
        {
            maxnum.push_back(max(nums[i] + maxnum[i - 2], maxnum[i - 1]));
        }
        return maxnum[nums.size() - 1];
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2,7,9,3,1};
    cout<<solution.rob(nums);
    return 0;
}