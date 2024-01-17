#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int binary[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string sign[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string now_str;
        unordered_map<string, int> num;
        int result = 0;
        for(int i = 0; i < 13; i++)
            num[sign[i]] = binary[i];
        for(int i = 0; i < s.size();)
        {
            now_str = s[i];
            if(s[i] == 'C')
            {
                if((i+1)>=s.size()){now_str = "C";}
                else{
                    if(s[i + 1] == 'M') {now_str = "CM"; i++;}
                    else if(s[i + 1] == 'D'){now_str = "CD"; i++;}
                }
                
            }
            else if(s[i] == 'X')
            {
                if((i+1)>=s.size()){now_str = "X";}
                else{
                    if(s[i + 1] == 'C'){now_str = "XC"; i++;}
                    else if(s[i + 1] == 'L'){now_str = "XL"; i++;}
                }
                
            }
            else if(s[i] == 'I')
            {   if((i+1)>=s.size()){now_str = "I";}
                else{
                    if(s[i + 1] == 'X'){now_str = "IX"; i++;}
                    else if(s[i + 1] == 'V'){now_str = "IV"; i++;}
                }
                
            }
            i++;
            result = result + num[now_str];


        }
        return result;
    }
};
int main() {
    Solution solution;
    string s = "MCMXCIV";
    cout<<solution.romanToInt(s);
    return 0;
}

/*
    看当前字母和右边字母大小关系
    比右边大，就加
    比右边小，就是减
*/