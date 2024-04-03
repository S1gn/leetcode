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
    int maxsum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxall(root);
        return maxsum;
    }

    int maxall(TreeNode* root)
    {
        int now = 0;
        if(!root) return 0;
        int left = max(maxall(root->left), 0);
        int right = max(maxall(root->right), 0);
        now = root->val + left + right;

        if(now > maxsum) maxsum = now;
        return root->val + max(left, right);

    }
};