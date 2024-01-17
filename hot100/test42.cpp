#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        // for(int i: height)
        //     sum += i;
        int i = 0;
        int j = height.size() - 1;
        int now_height = 0;
        while(i!=j)
        {
            if(height[i] > height[j])
            {
                if(height[j] > now_height){
                    now_height = height[j];
                    fill(height, now_height, i, j, sum);
                    j--;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                if(height[i] > now_height){
                    now_height = height[i];
                    fill(height, now_height, i, j, sum);
                    i++;
                }
                else
                {
                    i++;
                }

            }
        }
        return sum;
    }
    void fill(vector<int>& height, int h, int start, int end, int &f)
    {
        for(int i = start; i< end; i++)
            if(height[i] < h) 
            {
                f = f + h - height[i];
                height[i] = h;
            }
                
    }
};
int main() {
    Solution solution;
    vector<int> height = {4,2,0,3,2,5};
    cout<<solution.trap(height);
    return 0;
}