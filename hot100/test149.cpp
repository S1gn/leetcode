#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int gcd(int a, int b)
    {
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        
        int ret = 0;
        for(int i = 0; i<n; i++)
        {
            unordered_map<int, int> mp;
            if(ret >= n - 1 || ret > n / 2)
                return ret;
            for(int j = i + 1; j<n; j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if(x == 0)
                    y = 1;
                else if(y == 0)
                    x = 1;
                else
                {
                    if(y < 0)
                    {
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(abs(x), abs(y));
                    x = x / gcdXY;
                    y = y / gcdXY;
                }
                mp[y + x * 20001]++;
            }
             int maxn = 0;
            for (auto& [_, num] : mp) {
                maxn = max(maxn, num + 1);
            }
            ret = max(ret, maxn);
        }
    }
};
int main() {
    Solution solution;
    return 0;
}