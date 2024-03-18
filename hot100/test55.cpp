#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 0.5;
        for(int i=0; i<nums.size(); i++)
        {
            if(step<0)
                return false;
            if(nums[i]>step)
            {
                step = nums[i];
            }
            step--;
        }
        return true;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0};
    cout<<solution.canJump(nums);
    return 0;
}