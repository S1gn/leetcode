#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }


};

int main() {
    Solution solution;
    vector<int> nums ={0,0,1,1,1,1,2,3,3};
    int len = solution.removeDuplicates(nums);
    for(int i=0; i< len; i++)
        cout<<nums[i];
    return 0;
}