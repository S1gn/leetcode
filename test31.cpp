#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() -1; i>0; i--)
        {
            if(nums[i]>nums[i-1])
            {
                findminbig(nums, i-1);
                sort(nums, i);
                return;
            }
        }
        sort(nums, 0);
    }
    void findminbig(vector<int>& nums, int index)
    {
        int max = nums[index+1];
        int flag = index+1;
        for(int i = index+1; i< nums.size();i++)
        {
            if(nums[i]<max && nums[i]>nums[index])
            {
                flag = i;
                max = nums[i];
            }
        }
        int temp = nums[index];
        nums[index] = nums[flag];
        nums[flag] = temp;
    }
    void sort(vector<int>&nums, int index)
    {
        for(int i = index; i<nums.size()-1;i++)
        for(int j =i+1; j<nums.size();j++)
        {
            if(nums[i]>nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    solution.nextPermutation(nums);
    for(int i:nums)
    cout<<i;
    return 0;
}