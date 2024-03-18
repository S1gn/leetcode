#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        if(citations.size() == 1 && citations[0] > 0) return 1;
        int index=0;
        for(int i=citations.size() - 1; i>=0; i--)
        {
            if((citations.size() - i) >= citations[i])
            {
                if(index < citations[i])
                    index = citations[i];
            }
            else
            {
                if(citations[i] > index)
                    index++;
            }
        }
        return index;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 3, 1};
    cout<<solution.hIndex(nums);
    return 0;
}