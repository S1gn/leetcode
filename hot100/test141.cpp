#include <iostream>
#include <vector>
using namespace std;



struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        if(head->next == nullptr) return false;
        ListNode* p1 = head->next;
        ListNode* p2 = head;
        while(p1 != p2)
        {
            if(p1 == nullptr || p1 -> next == nullptr)
                return false;
            p1 = p1->next->next;
            p2 = p2->next;
        }
        return true;
    }
};
int main() {
    Solution solution;
    return 0;
}