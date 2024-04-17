#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        int nowcapital = w;
        int sum = nowcapital;
        vector<pair<int, int>> arr;
        for(int i = 0; i<profits.size(); i++)
        {
            arr.push_back({profits[i], capital[i]});
        }
        
        sort(arr.begin(), arr.end(), compare);
        int index = 0;
        for(int i=0; i<k; i++)
        {
            for(index; index< arr.size(); index++)
            {
                if(arr[index].second > nowcapital)
                    break;
                else
                    pq.push(arr[index].first);
            }
            if(pq.size() >0)
            {
                nowcapital  = nowcapital + pq.top();
                sum = sum + pq.top();
                pq.pop();
            }

        }
        return sum;
    }
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};
int main() {
    Solution solution;
    vector<int> pro = {1, 2, 3};
    vector<int> cap =  {1, 1, 2};
    cout<<solution.findMaximizedCapital(1, 2, pro, cap);
    return 0;
}