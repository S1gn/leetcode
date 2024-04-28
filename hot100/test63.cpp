#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        obstacleGrid[0][0] = -1;
        for(int i = 1; i < m; i++)
        {
            if(obstacleGrid[i][0] == 1)
                continue;
            else if(obstacleGrid[i - 1][0] == 1)
                obstacleGrid[i][0] = 0;
            else
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
            cout<< obstacleGrid[i][0]<<endl;
        }
        for(int i = 1; i < n; i++)
        {   
            if(obstacleGrid[0][i] == 1)
                continue;
            else if(obstacleGrid[0][i - 1] == 1)
                obstacleGrid[0][i] = 0;
            else
                obstacleGrid[0][i] = obstacleGrid[0][i - 1];
            
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else if(obstacleGrid[i][j - 1] == 1 && obstacleGrid[i - 1][j] == 1)
                    obstacleGrid[i][j] = 0;
                else if(obstacleGrid[i][j - 1] != 1 && obstacleGrid[i - 1][j] != 1)
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                else{
                    if(obstacleGrid[i][j - 1] == 1)
                        obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                    else
                        obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                }
                // cout<<obstacleGrid[i][j]<<i<<j<<endl;
            }
        }
        return -obstacleGrid[m - 1][n - 1];
    }
};
int main() {
    vector<vector<int>> t = {{0, 1},{0, 0}};
    Solution solution;
    cout<<solution.uniquePathsWithObstacles(t);
    return 0;
}