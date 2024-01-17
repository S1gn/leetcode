#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
     int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)return 0;
        int count = 0;
        int p = 0;
        for(int i = 0;i<nums.size() - 1; i++){
            if(nums[p] == val)
            {
                nums[p] = nums[i + 1];
                count++;
            }else{
                p++;
                nums[p] = nums[i+1];
            }
        }
        if(nums[nums.size()-1] == val) count++; 
        return nums.size() - count;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout<<solution.removeElement(nums, 2)<<endl;
    for(int i:nums)
    cout<<i;
    return 0;
}