#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int result = -1;
        while(left<= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return left;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 3, 4, 5};
    cout<<solution.searchInsert(nums, 0);
    return 0;
}