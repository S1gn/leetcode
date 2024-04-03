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

class BSTIterator {
private:
    vector<int> list;
    int index = 0;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            list.push_back(root->val);
            inorder(root->right);
        }
        else 
        return ;
    }
public:
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return list[index++];
    }
    
    bool hasNext() {
        return (index < list.size());
    }
};