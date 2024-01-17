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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode * start = new ListNode(-1);
        ListNode * end = new ListNode(-1);
        ListNode * p = new ListNode(-1);
        start -> next = head;
        head = start;
        end = start;
        int count = 0;
        
        while(end!=nullptr )
        {
            end = end->next;
            count++;
            if(count == k && end!=nullptr)
            {
                p = start->next;
                start->next = invert(p, end);
                start = p;
                end = start;
                count = 0;
            }
        }
        return head->next;
    }
    // 颠倒一个链表， last->[开始->head]
    ListNode* invert(ListNode* start, ListNode* end)
    {
        ListNode* q = start;
        ListNode* p = start->next;
        ListNode* r;
        start->next = end->next;
        while(p!=end)
        {
            r = q;
            q = p;
            p = p->next;
            q->next =r;
        }
        p->next = q;
        return end;
    }
};

int main()
{
    ListNode* node0 = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    Solution s;
    node0 = s.reverseKGroup(node1, 4);
    // node0->next = s.invert(node1, node2);
    // node1->next = s.invert(node3, node4);
    // cout<<node0->next->val<<endl;
    // cout<<node1->next->val<<endl;
    // cout<<node2->next->val<<endl;
    // // cout<<node3->next->val<<endl;
    // cout<<node4->next->val<<endl;
    cout<<node0->val<<endl;
    cout<<node0->next->val<<endl;
    cout<<node0->next->next->val<<endl;
    cout<<node0->next->next->next->val<<endl;
    return 0;

}