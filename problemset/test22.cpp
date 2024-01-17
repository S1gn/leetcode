#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<string> r;
        result.push_back("");
        for(int i = 0; i < 2 * n; i++)
            result = generate(result);
        for(int i =0; i < result.size(); i++)
        {
            if(isright(result[i], n))
            {
                r.push_back(translate(result[i]));
            }
        }
        return r;
    }
    vector<string> generate(vector<string> result)
    {
        vector<string> temp;
        for(string str:result)
        {
            temp.push_back(str + '0');
            temp.push_back(str + '1');
        }
        return temp;
    }
    bool isright(string str, int n)
    {
        int sum = 0;
        for(char c : str)
        {
            if(sum < 0 or sum > n) return false;
            if(c == '0') sum = sum + 1;
            else(sum = sum - 1);
        }
        if(sum == 0)return true;
        else return false;
    }
    string translate(string str)
    {
        string r;
        for(char c: str)
        {
            if(c == '0')
                r.push_back('(');
            else
                r.push_back(')');
        }
        return r;
    }
};
int main() {
    Solution solution;
    int n = 1;
    solution.generateParenthesis(n);
    return 0;
}

/*
由于开始必须是(，结尾必须是)，所以就是
*/