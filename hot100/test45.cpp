#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int Jump(vector<int>& nums) {
        vector<int> far;
        far.push_back(0);
        for(int i=0; i<nums.size();i++)
        {
            if(far.back() >= nums.size() - 1)
                break;
            if(i>=far.back())
            {
                far.push_back(far.back() + nums[i]);
            }
            for(int j = 0; j<far.size(); j++)
            {
                if(i<=far[j])
                {
                    if((nums[i] + i) > far.back())
                    {
                        if(j != far.size() - 1)
                        {
                            far.pop_back();
                            far.push_back(nums[i] + i);
                        }
                        else
                            far.push_back(nums[i] + i);
                    }
                }
            }
            
        }
        return far.size()-1;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    cout<<solution.Jump(nums);
    return 0;
}