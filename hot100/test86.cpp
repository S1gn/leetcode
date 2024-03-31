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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p0, *p3, *p4;
        ListNode *p1 = new ListNode(0);
        ListNode *p2 = new ListNode(0);
        p3 = p1;
        p4 = p2;
        p0 = head;
        while(p0)
        {
            if(p0->val < x)
            {
                p1->next = p0;
                p1 = p1->next;
            }
            else
            {
                p2->next = p0;
                p2 = p2->next;
            }
            p0 = p0->next;
        }
        p2->next = nullptr;
        if(p3->next)head = p3->next;
        else head = p4->next;
        p1->next = p4->next;
        
        return head;
    }

};
int main() {
    Solution solution;
    ListNode *a = new ListNode(1);
    // ListNode *b = new ListNode(4);
    // ListNode *c = new ListNode(3);
    // ListNode *d = new ListNode(2);
    // ListNode *e = new ListNode(5);
    // ListNode *f = new ListNode(2);
    // ListNode *g = new ListNode(5);
    // a ->next = b;
    // b ->next = c;
    // c ->next = d;
    // d ->next = e;
    // e ->next = f;
    // f ->next = g;
    a = solution.partition(a, 0);
    cout<<a->val;
    cout<<a->next->val;
    // cout<<a->next->next->val;
    // cout<<a->next->next->next->val;
    // cout<<a->next->next->next->next->val;
    // cout<<a->next->next->next->next->next->val;
    return 0;
}