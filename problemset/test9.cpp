#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string s = "";
        if(x < 0){
            return false;
        }
        while(x != 0){
            s = s + char(x % 10 + '0');
            x = x / 10;
        }
        for(int i=0; i<(s.size() + 1)/2; i++)
        {  
            if(s[i] != s[s.size() - i - 1])return false;
        }
        return true;

    }
};
int main() {
    Solution solution;
    int s = 121;
    cout << solution.isPalindrome(s);
    return 0;
}
/*
求解思路：
负数，末尾0非0全部false
求反转一半和剩下一半是否相同
当反转部分不小于剩下部分时，表示反转到中间
*/