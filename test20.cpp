#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<int> list;
        for(char c : s){
            if(c == '(')
            {
                list.push_back(0);
            }else if(c == '[')
            {
                list.push_back(1);
            }else if(c == '{')
            {
                list.push_back(2);
            }else if(c == '}')
            {
                if(list.size() == 0) return false;
                int a = list[list.size() - 1];
                if(a == 2){list.pop_back();}
                else{return false;}

            }else if(c == ']')
            {
                if(list.size() == 0) return false;
                int a = list[list.size() - 1];
                if(a == 1){list.pop_back();}
                else{return false;}
            }else if(c == ')')
            {
                if(list.size() == 0) return false;
                int a = list[list.size() - 1];
                if(a == 0){list.pop_back();}
                else{return false;}
            }
            
        }
        if(list.size() == 0) return true;
        return false;
    }
};
int main() {
    Solution solution;
    string s = "]";
    cout<<solution.isValid(s);
    return 0;
}