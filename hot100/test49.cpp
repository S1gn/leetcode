#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>>map;
        for(int i = 0; i<strs.size(); i++)
        {
            string key = str2str(strs[i]);
            if(map.find(key) != map.end())
                map[key].push_back(i);
            else
                {
                    vector<int> a = {i};
                    map[key] = a;
                }
        }
        for(auto i = map.begin(); i!=map.end(); i++)
        {
            vector<string> a;
            for(int j: i->second)
            {
                a.push_back(strs[j]);
            }
            result.push_back(a);
        }
        return result;
    }
    string str2str(string str)
    {
        vector<int> a;
        for(int i = 0; i<26; i++)
            a.push_back(0);
        for(char c: str)
        {
            a[c - 'a']++;
        }
        string b;
        for(int i: a)
            if(i>99) b = b + "100";
            else if(i>9)b = b + "0" + char(i/10 +'0') + char(i%10 +'0');
            else b = b + "00" + char('0' + i);
        return b;
    }
};
int main() {
    Solution solution;
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
    solution.groupAnagrams(s);
    // cout<<solution.str2str("aaa");
    return 0;
}