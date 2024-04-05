#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int width = board[0].size();
        int depth = board.size();

        for(int i = 0; i < width; i++)
        {
            if(board[0][i] == 'O')
                bfs(board, 0, i);
            if(board[depth - 1][i] == 'O')
                bfs(board, depth - 1, i);
        }
        for(int i = 0; i < depth; i++)
        {
            if(board[i][0] == 'O')
                bfs(board, i, 0);
            if(board[i][width - 1] == 'O')
                bfs(board, i, width - 1);
        }
        for(int i = 0; i < depth; i++)
            for(int j = 0; j < width; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        for(int i = 0; i < depth; i++)
            for(int j = 0; j < width; j++)
            {
                if(board[i][j] == '0')
                    board[i][j] = 'O';
            }
    }
    

    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        if(grid[x][y] == 'O')
            grid[x][y] = '0';
        else
            return;

        if((x + 1) < grid.size() && grid[x + 1][y] == 'O')
            bfs(grid, x + 1, y);
        if((x - 1) >= 0 && grid[x - 1][y] == 'O')
            bfs(grid, x - 1, y);
        if((y + 1) < grid[0].size() && grid[x][y + 1] == 'O')
            bfs(grid, x, y + 1);
        if((y - 1) >= 0 && grid[x][y - 1] == 'O')
            bfs(grid, x , y - 1);

    }
};