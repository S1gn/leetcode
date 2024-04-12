#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *right;
     TreeNode *left;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = BST(nums, 0, nums.size());
        return root;
    }

    TreeNode* BST(vector<int>& nums, int start, int end)
    {
        int mid = (start + end)/2;
        TreeNode* midnode = new TreeNode(nums[mid]);
        if(mid>start)midnode->left = BST(nums, start, mid);
        else midnode->left = nullptr;
        if(end > mid + 1)midnode->right = BST(nums, mid + 1, end);
        else midnode->right = nullptr;
        return midnode;
    }


};
int main() {
    Solution solution;
    return 0;
}