#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;   
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }
        while(k-- > 0 && !pq.empty())
        {
            pair<int, int> a = pq.top();
            pq.pop();
            ans.push_back(vector<int> {nums1[a.first], nums2[a.second]});
            if(a.second + 1 < n)
                pq.emplace(a.first, a.second + 1);
        }
        return ans;

    }
};
int main() {
    Solution solution;
    return 0;
}