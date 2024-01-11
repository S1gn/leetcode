#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string now_str;
        for(int i = 0;;i++){
            for(string str:strs){
                if(i >= str.size()) return now_str;
                
                if(str[i]!=strs[0][i])
                    return now_str;
            }
            if(now_str.size()<=i){   
                now_str.push_back(strs[0][i]);
                continue;
            }
        }
        return now_str;
        
    }
};
int main() {
    Solution solution;
    vector<string> s = {"flower","flow","flight"};
    cout<<solution.longestCommonPrefix(s);
    return 0;
}

/*
二分查找
最短的字符串，分一半，先查前一半是否全体都有，都有，后一半切一半查前半部分
*/