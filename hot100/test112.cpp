#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return has(root, targetSum);
        
    }
    bool has(TreeNode* root, int targetSum)
    {
        if(!root) return false;
        if(root->val == targetSum && root->left == nullptr and root->right == nullptr)
            return true;
        if(targetSum < root->val)
            return false;
        else
        {
            return has(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        }
    }
};