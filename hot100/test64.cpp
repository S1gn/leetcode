#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            if(i != 0)
                grid[i][0] = grid[i][0] + grid[i - 1][0];
            for(int j = 1; j<n; j++)
            {
                if(i == 0)
                {
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                }
                else
                {
                    grid[i][j] = grid[i][j] + min(grid[i][j - 1], grid[i - 1][j]);
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};
int main() {
    vector<vector<int>> t = {{1,2},{1,1}};
    Solution solution;
    cout<<solution.minPathSum(t);
    return 0;
}