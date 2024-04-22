#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int last = 0;
        int now = 0;
        while(i >= 0 || j >= 0)
        {
            
            if(i < 0)
            {
                now = b[j] - '0' + last;
                last = now / 2;
                now = now % 2;
                j--;
            }
            else if(j < 0)
            {
                now = a[i] - '0' + last;
                last = now / 2;
                now = now % 2;
                i--;
            }
            else
            {
                now = a[i] - '0' + b[j] - '0' + last;
                last = now / 2;
                now = now % 2;
                i--;
                j--;
            }
            cout<<i<<j<<now<<last<<endl;
            res  = res + char(now + '0');
        }
        if(last > 0)
            res = res + '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    Solution solution;
    cout<<solution.addBinary("1", "111");
    return 0;
}