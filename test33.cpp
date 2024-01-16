#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int result = -1;
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) if(nums[0] == target) return 0;else return -1;
        if(nums[0] == target) result = 0;
        for(i = 1; i<nums.size() ; i++)
        {
            if(nums[i] == target) result = i;
            if(nums[i-1]>nums[i])break;
        }
        vector<int> newnums(nums.begin() + i, nums.end());
        if(result == -1)
        {
            result = binarySearch(newnums, target);
            if(result!=-1)
                result = result + i ;
        }
        newnums.insert(newnums.end(), nums.begin(), nums.begin() + i);
        
        nums = newnums;
        return result;
    }
    int binarySearch(vector<int>& nums, int target){
        if(nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) { 
                return mid; 
            } else if(nums[mid] < target) { 
                left = mid + 1; 
            } else { 
                right = mid - 1; 
            }
        }
        // End Condition: left > right
        return -1;
    }

};
int main() {
    Solution solution;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<solution.search(nums, 4);
    return 0;
}

/*
因为数字唯一，二分查找可以看出来哪边有序
*/