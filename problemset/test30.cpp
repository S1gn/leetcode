#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        // 设 words中所有单词的长度为 d
        int n = s.size(), m = words.size(), d = words[0].size();
        int len = 0;
        unordered_map<string, int> um;
        for (string w : words) {
            len += w.size();
            um[w]++;
        }

        // init: 初始化长度为 d 的数组
        vector<unordered_map<string, int> > vu(d);
        for (int i = 0; i < d && i + len <= n; i++) {
            for (int j = i; j < i + len; j += d) {
                string w = s.substr(j, d);
                vu[i][w]++;
            }
            if (vu[i] == um) {
                res.emplace_back(i);
            }
        }

        // sliding window: 滑动窗口，每次移动 d 个位置
        for (int i = d; i + len <= n; i++) {
            int r = i % d;
            string wa = s.substr(i - d, d), wb = s.substr(i + len - d, d);
            if(--vu[r][wa] == 0) vu[r].erase(wa);
            vu[r][wb]++;
            if (vu[r] == um) {
                res.emplace_back(i);
            }
        }

        return res;

    }

};
int main() {
    Solution solution;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    vector<int> a = solution.findSubstring(s, words);
    for(int i :a)
        cout<<i;
    return 0;
}