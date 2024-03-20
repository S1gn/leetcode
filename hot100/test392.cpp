#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(i < s.length() && j < t.length())
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == s.length())
        return true;
        else return false;
    }
};
int main() {
    Solution solution;
    string s ="axc";
    string t = "ahbgdc";
    cout<<solution.isSubsequence(s, t);
    return 0;
}