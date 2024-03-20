#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        sum = nums[0];
        int minsize = nums.size() + 1;
        while(end < nums.size())
        {
            if(sum < target)
            {
                end++;
                if(end == nums.size())
                    break;
                sum += nums[end];
            }
            else if(sum >=target)
            {
                if(minsize>end - start)
                    minsize = end - start + 1;
                sum -=nums[start];
                start++;
            }
        }
        if(minsize == nums.size() + 1)
            return 0;
        return minsize;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout<<solution.minSubArrayLen(11, nums);
    return 0;
}