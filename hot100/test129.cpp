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
    vector<int> nums;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int re = 0;
        getnum(root, 0);
        for(int i:nums)
        {
            re += i;
        }
        return re;
    }
    void getnum(TreeNode* root, int now)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            now = now * 10 + root->val;
            nums.push_back(now);
        }
        else
        {
            now = now * 10 + root->val;
            getnum(root->left, now);
            getnum(root->right, now);
        }
    }
};