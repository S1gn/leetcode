#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        int sum = 0;
        string num = "";
        int s1gn = 1;
        signs.push(1);
        for(char c:s)
        {
            
            if(c =='+')
            {
                sum = sum +  s1gn * atoi(num.c_str());
                num = "";
                s1gn = signs.top();
            }
            else if(c == '-')
            {
                sum = sum +  s1gn * atoi(num.c_str());
                 num = "";
                s1gn = -signs.top();
            }
            else if(c == '(')
            {
                sum = sum +  s1gn * atoi(num.c_str());
                 num = "";
                signs.push(s1gn);
            }
            else if(c == ')')
            {
                sum = sum +  s1gn * atoi(num.c_str());
                 num = "";
                signs.pop();
            }
            else if(c== ' ')
                continue;
            else{
                num += c;
            }
        }
        sum = sum  + s1gn * atoi(num.c_str());
        return sum;
    }
};
int main() {
    Solution solution;
    vector<string> a = {"4","13","5","/","+"};
    solution.evalRPN(a);
    return 0;
}