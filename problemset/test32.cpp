#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int a = getnum(s);
        
        int b = getnum(reverse(s));
        return max(a,b);
    }
    int getnum(string s)
    {
        int sum = 0;
        int start = 0;
        int end = 0;
        int result = 0;
        for(int i = 0; i< s.size(); i++)
        {
            char c = s[i];
            // cout<<start<<end<<endl;
            if(c == '(')
                sum = sum + 1;
            else
                sum = sum - 1;

            if(sum<0)
            {
                if((end - start)>result)
                {
                    result = end - start;
                }
                start = i + 1;
                end = i + 1;
                sum = 0;
            }
            else if(sum == 0)
            {
                end++;
                if((end - start)>result)
                {
                    result = end - start;
                }
                
            }
            else{
                end++;
            }
        }
        
        return result;
    }
    string reverse(string s)
    {
        string a;
        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i] == '(')a.push_back(')');
            else a.push_back('(');
        }
        return a;
    }
};
int main() {
    Solution solution;
    string s = ")()()";
    cout<<solution.longestValidParentheses(s);
    return 0;
}

/*
可以考虑堆栈
*/