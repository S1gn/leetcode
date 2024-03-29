#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node* random;
    Node(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> map;
        vector<Node*> result;
        Node* p = head;
        int i = 0;
        while(p)
        {
            Node* start = (Node*) malloc(sizeof(Node));
            start->val = p->val;
            result.push_back(start);
            map[p] = i;
            i++;
            p = p->next;
        }

        p = head;
        i = 0;
        while(p)
        {
            if(p->next)result[i] -> next = result[i + 1];
            if(p->random)
                result[i] ->random = result[map[p->random]];
            else
                result[i] ->random = nullptr;
            p=p->next;
            i++;
        }
        result[i - 1] -> next =nullptr;
        return result[0];
    }
};
int main() {
    Solution solution;
    return 0;
}