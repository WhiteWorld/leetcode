/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*关键，1. 新一个指向head的指针， 2. 保存prev*/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode * pos = new ListNode(0);
        pos->next = head;
        ListNode *cur = head;
        ListNode *prev = pos;
        ListNode *result = pos;
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        while(cur){
            if(cur->val < x){
                if(pos->next == cur){
                    prev = cur;
                    cur = cur->next;
                    pos = prev;
                }else{
                    prev->next = cur->next;
                    cur->next = pos->next;
                    pos->next = cur;
                    
                    pos = pos->next;
                    cur= prev->next;
                }
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return result->next;
    }
};