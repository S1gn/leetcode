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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* p0 = p;
        int size = 0;
        while(p!= NULL)
        {
            p = p->next;
            size++;
        }
        n = size - n;
        p = head;
        if(n == 0)return head->next;
        for(int i=0 ;i <n; i++)
        {
            p0 = p;
            p = p->next;
        }
        p0->next = p ->next;
        delete p;
        return head;
    }
};