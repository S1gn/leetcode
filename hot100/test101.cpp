#include <iostream>
#include <vector>
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
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        if(root->left == nullptr || root->right == nullptr)
            return false;
        else
            return isSameTree(root->left, root->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        cout<<1;
        if(p==nullptr && q == nullptr)
            return true;
        else if((p == nullptr && q!= nullptr) || (p!=nullptr && q==nullptr))
            return false;
            
        if(p->val == q->val)
            return isSameTree(p->left, q->right)&&isSameTree(p->right, q->left);
        else
            return false;
    }
};
int main() {
    Solution solution;
    return 0;
}