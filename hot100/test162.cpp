#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findBinaryPeak(nums, 0, nums.size() - 1);
    }

    int findBinaryPeak(vector<int>& nums, int l, int r)
    {
        int mid = l + (r - l) / 2;
        if(mid == 0)
        {
            if(nums.size() == 1)
                return mid;
            else if (nums[mid] > nums[mid + 1])
                return mid;
        }
        if(mid == nums.size() - 1)
        {
            if(nums.size() == 1)
                return mid;
            else if(nums[mid - 1] < nums[mid])
                return mid;
        }
        if(mid > 0 && (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]))
            return mid;
        if(nums[mid + 1] > nums[mid])
            return findBinaryPeak(nums, mid + 1, r);
        else if(nums[mid - 1] > nums[mid])
            return findBinaryPeak(nums, l, mid);
        return 0;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 1};
    cout<<solution.findPeakElement(nums);
    return 0;
}