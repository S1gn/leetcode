#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum1, sum2, sum;
        sum1 = nums[0] + nums[1] + nums[2];
        sum2 = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && (nums[i] == nums[i-1])) continue;
            // if(nums[i] > target)break;
            int L = i + 1;
            int R = nums.size() - 1;
            while(L<R)
            {
                sum =  nums[i] + nums[L] + nums[R];
                if(sum - target > 0){R--;if(abs(sum-target)<abs(sum1-target)) sum2 = sum;}
                else if(sum - target < 0){L++; if(abs(sum-target)<abs(sum2-target)) sum2 = sum;}
                else if(sum - target == 0){
                    return target;
                }
            }
        }
        cout<<sum1<<sum2<<endl;
        if(abs(sum1 - target) > abs(target - sum2))
            return sum2;
        else
            return sum1;
    }
};
int main() {
    Solution solution;
    vector<int> s = {1,1,1,5,5,5,5,5,5};
    cout<<solution.threeSumClosest(s, 14);
    return 0;
}