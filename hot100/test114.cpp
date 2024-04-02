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
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        dfs(root, l);
        int i;
        for(i=0; i<l.size()-1; i++)
        {
            l[i]->right = l[i+1];
            l[i]->left =nullptr;
        }
        l[i] -> left = nullptr;
        l[i] -> right = nullptr;
    }
    void dfs(TreeNode* root, vector<TreeNode*> &l)
    {
        if(root)
            l.push_back(root);
        else
            return;
        dfs(root->left, l);
        dfs(root->right, l);
    }
};