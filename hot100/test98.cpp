#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    bool isValidBST(TreeNode* root) {
        return isChildBST(root, INT32_MAX, INT32_MIN);
    }

    bool isChildBST(TreeNode* root, int up, int down)
    {
        if(!root) return true;
        if(root->val > down && root->val < up)
        {
            bool left = true;
            bool right = true;
            if(root->left) left = isChildBST(root->left, root->val, down);
            if(root->right) right = isChildBST(root->right, up, root->val);
            return left&&right;
        }
        else
        {
            return false;
        }
    }
};