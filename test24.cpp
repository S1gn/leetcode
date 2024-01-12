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
    ListNode* swapPairs(ListNode* head) {
        ListNode* r = new ListNode(-1);
        ListNode* p = new ListNode(-1);
        p = r;
        r -> next = head;
        while(r != nullptr)
        {
            r = swap(r, head);
            if(r)head = r -> next;
            cout<<r->val<<head->val<<endl;
        }
        return p->next;
    }
    ListNode* swap(ListNode* last, ListNode* head)
    {
        ListNode* p0 = new ListNode(-1);
        ListNode* p1 = new ListNode(-1);
        if(head != nullptr)p0 = head; else return nullptr;
        if(head -> next != nullptr) p1 = head->next; else return nullptr;
        
        last->next = p1;
        p0->next = p1->next;
        p1->next = p0;
        cout<<p0->val<<p1->val<<endl;
        return head;
    }
};

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    Solution s;
    s.swapPairs(node1);
    return 0;

}