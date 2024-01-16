#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(nums[mid] == target)
            {
                result.push_back(searchleftb(nums, mid));
                result.push_back(searchrightb(nums, mid));
                break;
            }
            else if(nums[mid]>target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if(result.size() == 0) {result.push_back(-1);result.push_back(-1);}
        return result;
    }
    int searchleftb(vector<int>& nums, int mid)
    {
        int result = -1;
        for(int i = mid; i>=0; i--)
        {
            if(nums[i] == nums[mid])result = i;
            else break;
        }
        cout<<result;
        return result;
    }
    int searchrightb(vector<int>& nums, int mid)
    {
        int result = -1;
        for(int i = mid; i<nums.size(); i++)
        {
            if(nums[i] == nums[mid])result = i;
            else break;
        }
        cout<<result;
        return result;
    }

    
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 2, 4};
    solution.searchRange(nums, 3);
    return 0;
}

/*
可以更改二分查找的条件
*/