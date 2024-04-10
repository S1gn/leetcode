#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
    
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;
        vector<string> now;
        dfs(n, 0, now, columns, diagonals1, diagonals2);
        return res;
    }

    void dfs(int n, int line, vector<string>now, unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
    {
        if(line == n)
        {
            res.push_back(now);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(columns.find(i) != columns.end())
                continue;
            int s1 = line - i;
            if(diagonals1.find(s1) != diagonals1.end())
                continue;;
            int s2 = line + i;
            if(diagonals2.find(s2) != diagonals2.end())
                continue;
            
            columns.insert(i);
            diagonals1.insert(s1);
            diagonals2.insert(s2);
            string temp = "";
            for(int j = 0; j<n; j++)
            {
                if(i == j)
                    temp = temp + "Q";
                else
                    temp = temp + ".";
            }
            now.push_back(temp);
            dfs(n, line + 1, now, columns, diagonals1, diagonals2);
            columns.erase(i);
            diagonals1.erase(s1);
            diagonals2.erase(s2);
            now.pop_back();

        }
    }
};

int main() {
    Solution solution;
    solution.solveNQueens(4);
    for(auto p: solution.res)
        for(string s: p)
            cout<<s<<endl;
    return 0;
}