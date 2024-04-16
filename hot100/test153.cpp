#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findRoMin(nums, 0, nums.size() - 1);
    }
    int findRoMin(vector<int>& nums, int l, int r)
    {
        int mid = l + (r - l) / 2;
        if(l == r)
            return nums[l];
        if(nums[l] > nums[l + 1])
            return nums[l + 1];
        if(nums[l] < nums[r])
            return nums[l];
        if(nums[l] > nums [r])
        {
            if(nums[mid] > nums[l])
                return findRoMin(nums, mid, r);
            else if(nums[mid] < nums[l])
                return findRoMin(nums, l, mid);
        }

    }
};
int main() {
    Solution solution;
    vector<int> nums = {1};
    cout<<solution.findMin(nums);
    return 0;
}