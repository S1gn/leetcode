#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> map;
        int max = 0;
        int maxkey = -1;
        for(int i: nums)
        {
            if(map.find(i) == map.end()) map[i] = 1;
            else map[i] ++;
            if(map[i] > max)
            {
                max = map[i];
                maxkey = i;
            }
            if(max > nums.size()/2)
                return maxkey;
        }
        return maxkey;

    }
};
int main() {
    Solution solution;
    vector<int> nums = {6, 5, 5};
    cout<<solution.majorityElement(nums);
    return 0;
}

/*
很多方法
*/