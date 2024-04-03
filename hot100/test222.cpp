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
    int last = 0;
    int hmax = 0;
    int countNodes(TreeNode* root) {
        geth(root, hmax);
        gethl(root, 0);
        return pow(2, hmax - 1) - 1 + last;
    }
    void gethl(TreeNode* root, int h)
    {   
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr && h == hmax - 1)
        {
            last++;
        }
        else{
            h = h + 1;
            if(h > hmax) hmax = h;
            gethl(root->left, h);
            gethl(root->right, h);
        }

    }
    void geth(TreeNode* root, int &h)
    {
        while(root)
        {
            h = h + 1;
            root = root ->left;
        }
    }

};