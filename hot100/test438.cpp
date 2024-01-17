#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int psize = p.size();
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int sum = 0;
        for(int i = 0; i<psize; i++)
        {
            if(map1.find(p[i])!=map1.end())map1[p[i]]++;
            else map1[p[i]] = 1;
            map2[p[i]] = 0;
        }
        for(int i = 0; i<psize; i++)
        {
            if(map2.find(s[i]) != map2.end())
                map2[s[i]]++;
        }
        for(int i = 0; i+psize <=s.size(); i++)
        {
            if(isp(map2, map1)) result.push_back(i);
            if(map2.find(s[i]) != map2.end())
            {
                map2[s[i]]--;
            }
            if(map2.find(s[i + psize]) != map2.end())
            {
                map2[s[i + psize]]++;
            }
            
        }
        return result;
    }
    bool isp(unordered_map<char, int> map2, unordered_map<char, int> map1)
    {
        for(auto i=map2.begin(); i!= map2.end(); i++)
        {
            if(map1[i->first] != i->second)return false;
        }
        return true;
    }
};
int main() {
    Solution solution;
    string s = "baa";
    string p = "aa";
    for(int i :solution.findAnagrams(s, p))
    cout<<i;
    return 0;
}