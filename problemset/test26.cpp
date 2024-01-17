#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int count = 1;
        for(int i = 1;i<nums.size(); i++){
            if((nums[i]>nums[i-1]))
            {
                nums[count] = nums[i];
                count++;
            }
        }
        nums.assign(nums.begin(), nums.begin() + count);
        return count;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 5};
    cout<<solution.removeDuplicates(nums)<<endl;
    for(int i:nums)
    cout<<i;
    return 0;
}