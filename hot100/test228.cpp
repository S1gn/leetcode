#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0;
        vector<string> result;
        while(start < nums.size())
        {
            string s = getrange(nums, start);
            cout<<s<<endl;
            result.push_back(s);
        }
        return result;
    }

    string getrange(vector<int>& nums, int &start)
    {
        int firstnum = nums[start];
        int prev = firstnum;
        for(int i = start + 1; i < nums.size(); i++)
        {
            if((nums[i] - prev) == 1)
            {
                prev = nums[i];
            }
            else
            {
                if(prev != firstnum)
                {
                    start = i;
                    return to_string(firstnum) + "->" + to_string(prev);
                }
                else
                {
                    start = i;
                    return to_string(firstnum);
                }
            }
        }
        if(prev == firstnum)
        {
            start++;
            return to_string(firstnum);
        }
        else{
            start = nums.size();
            return to_string(firstnum) + "->" + to_string(prev);
        }
    }
};
int main() {
    Solution solution;
    vector<int> a = {-2147483648,-2147483647,2147483647};
    solution.summaryRanges(a);
    return 0;
}