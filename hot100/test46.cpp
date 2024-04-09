#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int> output, int start) {
        if(start == output.size())
        {
            ans.push_back(output);
            return;
        }
        for(int i = start; i < output.size(); i++)
        {
            swap(output[i], output[start]);
            dfs(output, start + 1);
            swap(output[i], output[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        dfs(nums, 0);
        return ans;
    }
};
int main() {
    Solution solution;
    return 0;
}