#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0;
        int result = 0;
        map[0] = 1;
        for(int i = 0;i <nums.size(); i++)
        {
            sum += nums[i];
            if(map.find(sum - k)!=map.end()) result += map[sum - k];
            map[sum]++;
        }
        return result;

    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, -1, 0};
    cout<<solution.subarraySum(nums, 0);
    return 0;
}