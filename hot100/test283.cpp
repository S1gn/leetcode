#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = 0; j<nums.size() - 1 - i; j++)
            {
                if(nums[j] == 0)
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0,0,1};
    solution.moveZeroes(nums);
    for(int i:nums)
    cout<<i;
    return 0;
}