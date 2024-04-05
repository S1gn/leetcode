#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j< grid[i].size(); j++)
                if(grid[i][j] == '1')
                {
                    num++;
                    bfs(grid, i, j);
                }
        return num;
    }

    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        if(grid[x][y] == '1')
            grid[x][y] = '0';

        if((x + 1) < grid.size() && grid[x + 1][y] == '1')
            bfs(grid, x + 1, y);
        if((x - 1) >= 0 && grid[x - 1][y] == '1')
            bfs(grid, x - 1, y);
        if((y + 1) < grid[0].size() && grid[x][y + 1] == '1')
            bfs(grid, x, y + 1);
        if((y - 1) >= 0 && grid[x][y - 1] == '1')
            bfs(grid, x , y - 1);

    }
};