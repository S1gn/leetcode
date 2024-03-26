#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word = "";
        vector<string> slist;
        for(char c:s)
        {
            if(c == ' ')
            {
                slist.push_back(word);
                word = "";
            }
            else
                word += c;
        }
        slist.push_back(word);
        
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        for (int i = 0; i < pattern.length(); i++) {
            char a = pattern[i];
            string b = slist[i];

            if (p2s.find(a) != p2s.end() && p2s[a] != b || 
                s2p.find(b) != s2p.end() && s2p[b] != a)
                return false;
            p2s[a] = b;
            s2p[b] = a;
        }
        return true && (pattern.size() == slist.size());

    }
};
int main() {
    Solution solution;
    string p = "aaa";
    string s = "aa aa aa aa";
    cout<<solution.wordPattern(p, s);
    return 0;
}