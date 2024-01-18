#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 0) return 0;
        int maxsu = nums[0];
        maxsub(nums, 0, maxsu);
        return maxsu;
    }

    int maxsub(vector<int> nums, int start, int &maxsu)
    {
        if(nums.size() - start == 1)
        {
            if(nums[start] > maxsu)
                maxsu = nums[start];
            if(nums[start] > 0)
                return nums[start];
            else
                return 0;
        }
        int b = maxsub(nums, start + 1, maxsu);
        int temp = max(nums[start] + b, nums[start]);
        if(temp > maxsu)
            maxsu = temp;
        return temp;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-2,-1};
    cout<<solution.maxSubArray(nums);
    return 0;
}

/*
分治法
*/