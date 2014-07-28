/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*普通链表操作*/
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        ListNode * hhead=new ListNode(0);
        hhead->next = head;
        
        ListNode *cur,*prev;
        cur=head->next;
        prev = head;
        while(cur){
            if(cur->val >= prev->val){
                prev = cur;
                cur = cur->next;
                continue;
            }
            ListNode *t=hhead;
            while(t->next->val < cur->val){
                t=t->next;
            }
            ListNode * curnext = cur->next;
            cur->next=t->next;
            t->next=cur;
            cur = curnext;
            prev->next = cur;
        }
        return hhead->next;
    }
};