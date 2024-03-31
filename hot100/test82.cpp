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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *h = new ListNode(0, head);
        ListNode *p1, *p2, *p0;
        p0 = h;
        p1 = head;
        p2 = head->next;
        int flag = 1;
        while(p2)
        {
            if(p2->val == p1->val)
            {
                if(flag == 1)
                {
                    flag = 0;
                    p2 = p2->next;
                }
                else
                {
                    p2 = p2->next;
                }
            }
            else
            {
                if(flag == 1)
                {
                    p0 = p0 ->next;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else
                {
                    // cout<<h->val<<p2->val<<endl;
                    p0->next = p2;
                    p1 = p2;
                    p2 = p2->next;
                    flag = 1;
                }
                
            }
        }
        if(flag == 0)
        {
            p0->next = nullptr;
        }
        return h->next;
    }

};
int main() {
    Solution solution;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(1);
    // ListNode *c = new ListNode(3);
    // ListNode *d = new ListNode(3);
    // ListNode *e = new ListNode(4);
    // ListNode *f = new ListNode(4);
    // ListNode *g = new ListNode(5);
    a ->next = b;
    // b ->next = c;
    // c ->next = d;
    // d ->next = e;
    // e ->next = f;
    // f ->next = g;
    solution.deleteDuplicates(a);
    return 0;
}