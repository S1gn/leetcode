#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        vector<Node*> l;
        q.push(root);
        Node* now = root;
        int count = 0;
        int i = 0;
        while (!q.empty()) {
            count = q.size();
            for (i = 0; i < count; i++) {
                now = q.front();
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
                q.pop();
                l.push_back(now);
            }
            for (i = 0; i < l.size() - 1; i++) {
                l[i]->next = l[i + 1];
            }
            l[i]->next = nullptr;
            l.clear();
        }
        return root;
    }

    
};