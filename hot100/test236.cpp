#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        string p1 = "";
        string q1 = "";
        encode(root, p, "0", p1);
        encode(root, q, "0", q1);
        int i = 0;
        int j = 0;
        while(true)
        {
            if(i>p1.length() || j>q1.length())
                break;
            if(p1[i++] == q1[j++])
                continue;
            else
                break;
        }
        string re = p1.substr(1, i - 1);
        TreeNode* temp = root;
        for(char c:re)
        {
            if(c == '0')
                temp = temp->left;
            else
                temp = temp->right;
        }
        return temp;

    }

    void encode(TreeNode* root, TreeNode* target, string str, string &re)
    {
        if(!root || re.length() > 0) return;
        if(root->left == target)
        {
            re = str + '0';
            return;
        }
        else if(root->right == target)
        {
            re = str + '1';
            return;
        }
        else
        {
            if(root->left) encode(root->left, target, str + '0', re);
            if(root->right) encode(root->right, target, str + '1', re);
        }
    }
};