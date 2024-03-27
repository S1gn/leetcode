#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , vector<int>> map;
        for(int i = 0; i<nums.size(); i++)
        {
            if(map.find(nums[i]) != map.end())
                map[nums[i]].push_back(i);
            else
                map[nums[i]].push_back({i});
        }
        for(auto p = map.begin(); p!=map.end(); p++)
        {
            int min1 = nums.size();// 最小
            int min2 = nums.size();// 第二小
            if(p->second.size() < 2) continue;
            for(int i = 0; i < p->second.size() - 1; i++)
            {
                if((p->second[i + 1] - p->second[i]) <= k)
                    return true;
            }
        }
        return false;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 0, 1, 1};
    cout<<solution.containsNearbyDuplicate(nums, 1);
    return 0;
}