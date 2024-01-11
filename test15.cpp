#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && (nums[i] == nums[i-1])) continue;
            if(nums[i] > 0)break;
            int L = i + 1;
            int R = nums.size() - 1;
            while(L<R)
            {
                if(nums[i] + nums[L] + nums[R] > 0)R--; 
                else if(nums[i] + nums[L] + nums[R] < 0)L++;
                else if(nums[i] + nums[L] + nums[R] == 0){
                    cout<<nums[i]<< nums[L]<< nums[R]<<endl;
                    result.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    while(((L) < nums.size() - 1) && nums[L-1] == nums[L])
                        L++;
                    while(((R) > 0) && nums[R+1] == nums[R])
                        R--;
                }
            }
        }
        return result;

}
};
int main() {
    Solution solution;
    vector<int> s = {-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};
    solution.threeSum(s);
    return 0;
}

/*
不重复双指针，再加入结果后，两者都要移动
移动后还要直到移动到非同数字
并且实时判断退出条件
*/