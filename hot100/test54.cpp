#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int x1 = 0;
        int y1 = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while(res.size()<matrix.size() * matrix[0].size())
        {
            out(matrix, x1, y1, m, n, res);
            x1 = x1 + 1;
            y1 = y1 + 1;
            n = n -1;
            m = m-1;
            
        }
        
        
    }
    void out(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, vector<int>&result)
    {
        cout<<x1<<y1<<x2<<y2<<endl;
        for(int i = y1; i < y2; i++)
        {
            result.push_back(matrix[x1][i]);
        }
        
        for(int i = x1 + 1; i < x2; i++)
        {
            result.push_back(matrix[i][y2 - 1]);
        }
        if((x2 - 1 > x1))
            for(int i = y2 - 2; i >= y1; i--)
            {
                result.push_back(matrix[x2 - 1][i]);
            }
        if((y2 - 1 > y1))
        for(int i = x2 - 2; i >= x1 + 1; i--)
        {
            result.push_back(matrix[i][y1]);
        }
    }
};
int main() {
    Solution solution;
    vector<vector<int>> matrix = {vector<int>{7}, vector<int>{9},vector<int>{6}};
    solution.spiralOrder(matrix);

    return 0;
}