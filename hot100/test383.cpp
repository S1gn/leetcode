#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
     bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>count;
        for(int i=0; i<magazine.length(); i++)
        {
            if(count.find(magazine[i]) != count.end())
                count[magazine[i]]++;
            else
                count[magazine[i]] = 1;
        }
        bool flag = 1;
        for(int i=0; i<ransomNote.length(); i++)
        {
            if(count.find(ransomNote[i]) != count.end())
            {
                if(count[ransomNote[i]] >= 1)
                    count[ransomNote[i]]--;
                else
                    return false;
            }
            else
                return false;
        }
        return flag;
    }
};
int main() {
    Solution solution;
    return 0;
}