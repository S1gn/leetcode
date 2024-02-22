#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        while(i<n)
        {
            while(j<m + i)
            {
                if(nums1[j]>nums2[i])
                {
                    for(int k = m + n - 1; k>j; k--)
                    {
                        nums1[k] = nums1[k - 1];
                    }
                    nums1[j] = nums2[i];
                    break;
                }
                j++;
                
            }
            if(j>=m + i)nums1[j++] = nums2[i];
            i++;
        }
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    for(int i: nums1)
        cout<<i;
    return 0;
}


/*
倒着比
*/