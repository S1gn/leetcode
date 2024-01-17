#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = words[0].size() * words.size();
        vector<int> result;
        if(s.size()<size) return result;

        unordered_map<string, int>map;
        for(string a:words)
            if(map.find(a) != map.end())
                map[a] = map[a] + 1;
            else
                map[a] = 1;
        for(int i=0; i<s.size() - size + 1; i++)
        {
            string str = s.substr(i, size);
            if(issub(str, map, words[0].size())) result.push_back(i);
        }
        return result;
    }
    bool issub(string str, unordered_map<string, int>map, int size)
    {
        int i=0;
        unordered_map<string, int> a(map);
        for(i=0; (i+size)<=str.size(); i = i +size)
        {
            string s = str.substr(i, size);
            auto p = a.find(s);
            if(p != a.end() && p->second != 0)
            {
                p->second = p->second - 1;
            }
            else
                return false;
        }
        return true;
    }
};
int main() {
    Solution solution;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    vector<int> a = solution.findSubstring(s, words);
    for(int i :a)
        cout<<i;
    return 0;
}