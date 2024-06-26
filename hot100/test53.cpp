#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        return maxSubArraySum(nums, 0, nums.size() - 1);
    }

    int maxsub(vector<int> nums, int left, int mid, int right)
    {
        // 一定会包含 nums[mid] 这个元素
        int sum = 0;
        int leftSum = INT32_MIN;
        // 左半边包含 nums[mid] 元素，最多可以到什么地方
        // 走到最边界，看看最值是什么
        // 计算以 mid 结尾的最大的子数组的和
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            if (sum > leftSum) {
                leftSum = sum;
            }
        }
        sum = 0;
        int rightSum = INT32_MAX;
        // 右半边不包含 nums[mid] 元素，最多可以到什么地方
        // 计算以 mid+1 开始的最大的子数组的和
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            if (sum > rightSum) {
                rightSum = sum;
            }
        }
        return leftSum + rightSum;
    }

    int maxSubArraySum(vector<int> nums, int left, int right)
    {
        if (left == right) {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftmax = maxSubArraySum(nums, left, mid);
        int rightmax = maxSubArraySum(nums, mid + 1, right);
        int midmax = maxsub(nums, left, mid, right);

        return max(leftmax, max(rightmax, midmax));
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-2,-1};
    cout<<solution.maxSubArray(nums);
    return 0;
}

/*
分治法
*/