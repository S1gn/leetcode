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
    unordered_map<int, int> s;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<preorder.size(); i++)
        {
            s[inorder[i]] = i;
        }
        return buildTree0(preorder, inorder, 0, preorder.size(), 0, preorder.size());
    }

    TreeNode* buildTree0(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
        if(s1 == e1 || s2 == e2)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[s1]);
        int mid = s[preorder[s1]];
        if(inorder[mid] == preorder[s1])
        {
            root->left = buildTree0(preorder, inorder, s1+1, s1+1+mid-s2, s2, mid);
            root->right = buildTree0(preorder, inorder, s1+1+mid-s2, e1, mid+1, e2);
        }
        return root;
       
    }
};