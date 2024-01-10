#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start, end, max = 0;
        for(start = 0, end = height.size() - 1; start < end;)
        {
            if((end - start) * min(height[start], height[end])>max)max = (end - start) * min(height[start], height[end]);
            if(height[start] < height[end]){start++;}
            else{end--;}
        }
        return max;

    }
};
int main() {
    Solution solution;
    vector<int> s = {1,8,6,2,5,4,8,3,7};
    cout<<solution.maxArea(s);
    return 0;
}
/*
面积 = （min(end, start）)*间距
小的内缩，有可能增大
大的内缩，一定变小
*/