#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> lastresult = {};
        if(digits.length() == 0) return lastresult;
        vector<string> result = {""};
        for(char c: digits)
        {
            lastresult = result;
            result = {};
            for(string s: lastresult)
            {
                string addlist = letter(c);
                for(char c2: addlist)
                {
                    result.push_back(s+c2);
                }
            }
        }
        return result;
    }
    string letter(char i)
    {
        if(i == '2') return "abc";
        if(i == '3') return "def";
        if(i == '4') return "ghi";
        if(i == '5') return "jkl";
        if(i == '6') return "mno";
        if(i == '7') return "pqrs";
        if(i == '8') return "tuv";
        if(i == '9') return "wxyz";
        return "";
    }
};
int main() {
    Solution solution;
    string s = "23";
    cout<<solution.letterCombinations(s).size();
    return 0;
}