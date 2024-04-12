#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if(grid.size() == 1)
            return new Node(grid[0][0], true);
        return bfs(grid, 0, 0, grid.size()/2);
    }

    Node* bfs(vector<vector<int>>& grid, int x, int y, int length)
    {
        Node* father;
        if(length == 1)
        {
            Node* tl = new Node(grid[x][y], true);
            Node* tr = new Node(grid[x][y + 1], true);
            Node* bl = new Node(grid[x + 1][y], true);
            Node* br = new Node(grid[x + 1][y + 1], true);
            if(tl->val == tr->val && tr ->val == bl->val && bl->val == br->val)
            {
                father = new Node(tl->val, true);
            }
            else
            {
                father = new Node(tl->val, false, tl, tr, bl, br);
            }
        }
        else
        {
            Node* tl = bfs(grid, x, y, length/2);
            Node* tr = bfs(grid, x, y + length, length/2);
            Node* bl = bfs(grid, x + length, y, length/2);
            Node* br = bfs(grid, x + length, y + length, length/2);
            if(tl->isLeaf && tr ->isLeaf && bl->isLeaf && br->isLeaf)
            {
                if(tl->val == tr->val && tr ->val == bl->val && bl->val == br->val)
                {
                    father = new Node(tl->val, true);
                }
                else
                {
                    father = new Node(tl->val, false, tl, tr, bl, br);
                }

            }
            else
            {
                father = new Node(tl->val, false, tl, tr, bl, br);
            }
        }
        return father;
    }
};