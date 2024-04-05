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
    unordered_map<TreeNode*, int> map;
    int kthSmallest(TreeNode* root, int k) {
        nodenum(root);
        TreeNode* temp = root;
        while(true)
        {
            cout<<map[temp->left];
            if(k>(map[temp->left] + 1))
            {
                k = k - map[temp->left] - 1;
                temp = temp->right;
            }
            else if(k == (map[temp->left] + 1))
            {
                return temp->val;
            }
            else if(k < (map[temp->left] + 1))
            {
                temp = temp->left;
            }
        }
    }

    int nodenum(TreeNode* root)
    {
        if(!root) return 0;
        if(root->left == nullptr && root->right == nullptr)
        {
            map[root] = 1;
            return 1;
        }
        int left = 0;
        int right = 0;
        if(root->left) left = nodenum(root->left);
        if(root->right) right = nodenum(root->right);
        map[root] = left + right + 1;
        return left + right + 1;
    }
};