#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    string a;
    cout<<solution.mySqrt(10);
    return 0;
}