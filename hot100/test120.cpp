#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int depth = triangle.size() - 1;
        for(int i = depth - 1; i >= 0; i--)
        {
            for(int j = 0; j<triangle[i].size(); j++)
            {
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                cout<<triangle[i][j]<<i<<j<<endl;
            }
        }
        return triangle[0][0];
    }
};
int main() {
    vector<vector<int>> t = {{2},{3,4},{6,5,7},{4,1,8,3}};

    Solution solution;
    cout<<solution.minimumTotal(t);
    return 0;
}