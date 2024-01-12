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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newlist = new ListNode(-1);
        newlist->next = nullptr;
        ListNode* p = newlist;
        while(list1 != nullptr and list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                p->next = list1;
                list1 = list1 -> next;
                p = p->next;
            }else{
                p->next = list2;
                list2 = list2 -> next;
                p = p->next;
            }
        }
        if(list1 != nullptr) p->next = list1;
        if(list2 != nullptr) p->next = list2;
        newlist = newlist -> next;
        return newlist;
    }
};

/*
    合并两个链表，数组可以用递归归并
*/