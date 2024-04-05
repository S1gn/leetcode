#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        if(!node) return nullptr;
        Node* root = new Node(node->val);
        map[node] = root;
        bfs(node, root, map);
        return root;
        
    }
    void bfs(Node* node0, Node* node1,  unordered_map<Node*, Node*> &map)
    {
        if(node0->neighbors.size() == node1->neighbors.size())
            return;
        for(int i = 0; i< node0->neighbors.size(); i++)
        {
            if(map.find(node0->neighbors[i]) != map.end())
            {
                node1->neighbors.push_back(map[node0->neighbors[i]]);
            }
            else
            {
                Node* temp = new Node(node0->neighbors[i]->val);
                map[node0->neighbors[i]] = temp;
                bfs(node0->neighbors[i], temp, map);
                node1->neighbors.push_back(map[node0->neighbors[i]]);
            }
        }
    }
};