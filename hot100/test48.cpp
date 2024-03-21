#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n/2; i++)
        {
            for(int j = 0; j<n; j++)
            {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }


    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {vector<int>{1, 2, 3}, vector<int>{4, 5, 6},vector<int>{7, 8, 9}};
    solution.rotate(matrix);

    return 0;
}