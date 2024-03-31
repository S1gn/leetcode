#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int i = 0;
        if(!head) return nullptr;
        ListNode* p = head;
        while(p->next)
        {
            p = p ->next;
            i++;
        }
        p -> next = head;
        p = head;
        int b = i - (k + 1)% i ;
        while(b)
        {
            p = p->next;
            b--;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }

};
int main() {
    Solution solution;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    // ListNode *f = new ListNode(4);
    // ListNode *g = new ListNode(5);
    a ->next = b;
    b ->next = c;
    c ->next = d;
    d ->next = e;
    // e ->next = f;
    // f ->next = g;
    a = solution.rotateRight(a, 2);
    cout<<a->val;
    cout<<a->next->val;
    cout<<a->next->next->val;
    cout<<a->next->next->next->val;
    cout<<a->next->next->next->next->val;
    // cout<<a->next->next->next->next->next->val;
    return 0;
}