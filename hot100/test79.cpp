#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string minStr;
        int minsize = s.size();
        unordered_map<char, int> map0;
        unordered_map<char, int> map1;
        if(s.size() < t.size()) return "";
        for(char c:t)
        {
            map1[c] = 0;
            if(map0.find(c) != map0.end()) map0[c]++;
            else map0[c] = 1;
        }
        
        int start = 0;
        int end = start + t.size() - 1;
        for(int i = 0; i<t.size(); i++)
        {
            if(map1.find(s[i])!=map1.end())map1[s[i]]++;
        }
        while(start<=s.size() - t.size())
        {
            if(iswindow(map0, map1))
            {
                if(end - start< minsize)
                {    
                    minsize = end - start + 1;
                    minStr = s.substr(start, minsize);
                }
                map1[s[start]]--;
                start++;
            }
            else{
                if(end<s.size()-1)
                {   
                    end++;
                    map1[s[end]]++;
                }else break;
            }
        }
        return minStr;
    }
    bool iswindow(unordered_map<char, int> map0, unordered_map<char, int> map1)
    {
        for(auto p= map0.begin(); p!=map0.end(); p++ )
        {
            if(p->second > map1.find(p->first)->second)return false;
        }
        return true;
    }
};
int main() {
    Solution solution;
    string s = "cabwefgewcwaefgcf";
    string t = "a";
    cout<<solution.minWindow(s, t);
    return 0;
}