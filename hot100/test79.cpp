#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool result;
    bool exist(vector<vector<char>>& board, string word) {
        result = false;
        for(int i = 0; i<board[0].size(); i++)
            for(int j = 0; j<board.size(); j++)
                if(board[i][j] == word[0] && !result)
                    dfs(board, word, 1, i, j, result);
        return result;
    }

    void dfs(vector<vector<char>>& board, string word, int index, int x, int y, bool &result)
    {
        // cout<<x<<y<<index<<endl;
        if(index == word.length())
        {
            result = true;
            return;
        }
        if(!result)
        {
            int ymax = board[0].size();
            int xmax = board.size();
            if(!result&&(x + 1 < xmax) && board[x + 1][y] == word[index])
            {
                char temp = board[x][y];
                board[x][y] = '0';
                dfs(board, word, index + 1, x + 1, y, result);
                board[x][y] = temp;
            }
            if(!result&&(x - 1 >= 0) && board[x - 1][y] == word[index])
            {
                
                char temp = board[x][y];
                board[x][y] = '0';
                dfs(board, word, index + 1, x - 1, y, result);
                board[x][y] = temp;
            }
            if(!result&&(y + 1 < ymax) && board[x][y + 1] == word[index])
            {
                char temp = board[x][y];
                board[x][y] = '0';
                dfs(board, word, index + 1, x, y + 1, result);
                board[x][y] = temp;
            }
            if(!result&&(y - 1 >= 0) && board[x][y - 1] == word[index])
            {
                char temp = board[x][y];
                board[x][y] = '0';
                dfs(board, word, index + 1, x, y - 1, result);
                board[x][y] = temp;
            }
        }
    }
};
int main() {
    Solution solution;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string s = "ABCCED";
    solution.exist(board, s);
    cout<<solution.result;
    return 0;
}