#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(vector<int> candidates, int cur, int sum, int target) {
        if(sum > target || cur == candidates.size())
            return;
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        sum = sum + candidates[cur];
        temp.push_back(candidates[cur]);
        dfs(candidates, cur, sum, target);
        sum = sum - candidates[cur];
        temp.pop_back();
        dfs(candidates, cur + 1, sum, target);

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, 0, target);
        return ans;
    }
};
int main() {
    Solution solution;
    return 0;
}