#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s1;
        unordered_map<char, int> t1;
        for(char c:s)
            if(s1.find(c)!=s1.end())
                s1[c]++;
            else
                s1[c] = 1;

        for(char c:t)
            if(t1.find(c)!=t1.end())
                t1[c]++;
            else
                t1[c] = 1;
        
        return s1==t1;
    }   
};
int main() {
    Solution solution;
    return 0;
}