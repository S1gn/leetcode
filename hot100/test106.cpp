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
/*
[3,9,20,15,7], [9,3,15,20,7], []不等9入栈
[3,9,20,15,7], [3,15,20,7]，[9] 不等，2入栈
[3,9,20,15,7], [15,20,7]，[9, 3]相等，创建3节点
[9,20,15,7], [15,20,7]，[9]相等，创建9节点
[20,15,7], [15,20,7]，[]不等，15入栈
[20,15,7], [20,7]，[15]不等，20入栈
[20,15,7], [7]，[15, 20]相等，创建20节点
[15,7], [7]，[15]相等，创建15节点
[7], [7]，[]不等，7入栈
[7], []，[7]相等，创建7节点
*/
class Solution {
public:
    unordered_map<int, int> s;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++)
        {
            s[inorder[i]] = i;
        }
        return buildTree0(inorder, postorder, 0, inorder.size(), 0, inorder.size());
    }

    TreeNode* buildTree0(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2) {
        if(s1 == e1 || s2 == e2)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[e2-1]);
        int mid = s[postorder[e2-1]];
        
        root->left = buildTree0(inorder, postorder, s1, mid, s2, s2+mid-s1);
        root->right = buildTree0(inorder, postorder, mid+1, e1, s2+mid-s1+1, e2-1);

        return root;
       
    }
};