#include <iostream>
#include <vector>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> re;
        if(!root) return re;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int sum = 0;
            for(int i=0; i<n;i++)
            {
                sum += q.front()->val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            re.push_back(sum/double(n));
        }
        return re;
    }
};