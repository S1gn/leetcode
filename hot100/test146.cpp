#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    int key;
    ListNode *next;
    ListNode* before;
    ListNode() : val(0), next(nullptr), before(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), before(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), before(nullptr) {}
 };
class LRUCache {
public:
    int capacity;
    ListNode* head;
    ListNode* end;
    unordered_map<int, ListNode*>map;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new ListNode(0);
        this->end = new ListNode(0);
        end->next = head;
        head->before = end;
        
    }
    
    int get(int key) {
        if(map.find(key)!=map.end())
        {
            ListNode* temp = map[key];
            temp->before->next = temp->next;
            temp->next->before = temp->before;
            temp->before = head->before;
            head->before->next = temp;
            temp->next = head;
            head->before = temp;
            return temp->val;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end())
        {
            ListNode* temp = map[key];
            temp->val = value;
            temp->before->next = temp->next;
            temp->next->before = temp->before;
            temp->before = head->before;
            head->before->next = temp;
            temp->next = head;
            head->before = temp;
        }
        else
        {
            if(map.size()>capacity)
            {
                map.erase(end->next->key);
                end->next = end->next->next;
                end->next->before = end;
            }
            else
            {
                ListNode* temp = new ListNode(value);
                temp->key = key;
                map[key] = temp;
                temp->before->next = temp->next;
                temp->next->before = temp->before;
                temp->before = head->before;
                head->before->next = temp;
                temp->next = head;
                head->before = temp;
            }
        }
    }
};