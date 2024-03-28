#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        int pos = points[0][1];
        int sum = 1;
        for(const vector<int> bollon: points)
        {
            if(bollon[0] > pos)
            {
                pos = bollon[1];
                sum++;
            }
        }
        return sum;
        
    }

    
};
int main() {
    Solution solution;
    return 0;
}