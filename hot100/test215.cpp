#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int heapsize = nums.size();
        buildmaxheap(nums, heapsize);
        for(int i = nums.size()-1; i>= nums.size() - k; i--)
        {
            swap(nums[0], nums[i]);
            --heapsize;
            maxHeapify(nums, 0, heapsize);
        }
        return nums[0];
    }
    void maxHeapify(vector<int>& nums, int i, int heapsize)
    {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int largest = i;
        if(l < heapsize && nums[l] > nums[largest]) largest = l;
        if(r < heapsize && nums[r] > nums[largest]) largest = r;

        if(largest!=i)
        {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, heapsize);
        }
    }
    void buildmaxheap(vector<int>& nums, int heapsize)
    {
        for(int i = heapsize/2; i>=0; i--)
            maxHeapify(nums, i, heapsize);
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1};
    
    return 0;
}