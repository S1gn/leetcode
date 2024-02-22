#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    solution.rotate(nums, 2);
    for(int i:nums)
    cout<<i;
    return 0;
}