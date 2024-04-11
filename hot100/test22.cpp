#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        stack<char> st;
        dfs("", st, n, 0);
        return res;
    }
    void dfs(string now, stack<char> &st, int n, int used)
    {
        if(now.length() == n * 2)
        {
            res.push_back(now);
            return;
        }
        if(used < n) 
        {
            st.push('(');
            now = now + "(";
            dfs(now, st, n, used + 1);
            st.pop();
            now = now.substr(0, now.length() - 1);
        }
        
        if(!st.empty())
        {
            st.pop();
            now = now + ")";
            dfs(now, st, n, used);
            st.push('(');
            now = now.substr(0, now.length() - 1);
        }

    }
};
int main() {
    Solution solution;
    solution.generateParenthesis(3);
    for(string s:solution.res)
        cout<<s<<endl;
    return 0;
}