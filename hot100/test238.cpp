#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l, r, result;
        int i;
        l.push_back(1);
        for(int i=1; i<nums.size(); i++)
        {
            l.push_back(l[i - 1] * nums[i - 1]); 
        }
        r.push_back(1);
        for(int i = nums.size() - 2; i >=0; i--)
        {
            r.push_back(r[r.size() - 1] * nums[i + 1]);
        }
        for(int i = 0; i <nums.size(); i++)
        {
            result.push_back(l[i] * r[nums.size() - 1 - i]);
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4};
    solution.productExceptSelf(nums);
    return 0;
}