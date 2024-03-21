#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // hang
        for(int i=0; i<9; i++)
        {
            unordered_map<char ,int> map;
            for(int j=0; j<9; j++)
            {
                if(map.find(board[i][j]) == map.end())
                    map[board[i][j]] = 1;
                else
                    if(board[i][j] != '.')
                        return false;
            }
        }
        // lie
        for(int i=0; i<9; i++)
        {
            unordered_map<char ,int> map;
            for(int j=0; j<9; j++)
            {
                if(map.find(board[j][i]) == map.end())
                    map[board[j][i]] = 1;
                else
                    if(board[j][i] != '.')
                        return false;
            }
        }
        // jiugongge
        for(int i=0; i<9; i++)
        {
            unordered_map<char ,int> map;
            for(int j=0; j<9; j++)
            {
                int x = (i/3)*3 + j/3;
                int y = (i*3)%9 + j%3;
                // cout<<x<<y<<endl;
                if(map.find(board[x][y]) == map.end())
                    map[board[x][y]] = 1;
                else
                    if(board[x][y] != '.')
                        return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    return 0;
}