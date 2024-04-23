#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int sum;
        int res = 0;
        for(int i = 0; i<32; i++)
        {
            sum = 0;
            for(int j = 0; j<nums.size(); j++)
            {
                sum += ((nums[j]>>i)&1);
            }
            res = res | (sum%3)<<i;

        }
        return res;
    }
};
int main() {
    Solution solution;
    cout<<solution.singleNumber({2, 2, 3, 2});
    return 0;
}