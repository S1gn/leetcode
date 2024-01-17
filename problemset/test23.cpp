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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return (ListNode *) nullptr;
        }
        for(int i = 1;i<lists.size(); i++)
        {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }

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
int main() {
    Solution solution;
    return 0;
}

/*
合并k个升序，直接变成归并排序，每两个一合
优化思路：二分合并，以空间换时间
动态队列：最小数决定合并顺序

*/