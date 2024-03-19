#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag = 0;
        int length = 0;
        for(int i = s.length() - 1; i>=0; i--)
        {
            if(s[i] == ' ' && flag == 0)
                continue;
            else if(s[i] == ' ' && flag == 1)
            {
                return length;
            }
            else if(s[i] != ' ')
            {
                flag = 1;
                length ++;
            }
        }
        return length;
    }
};
int main() {
    Solution solution;
    string s = "a";
    cout<<solution.lengthOfLastWord(s);
    return 0;
}