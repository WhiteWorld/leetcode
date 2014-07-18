/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 简单链表操作
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *head,*cur, *tmp;
        head = l1->val>=l2->val?l2:l1;
        cur = new ListNode(0);
        while(l1!=NULL&&l2!=NULL){
            if(l1->val < l2->val){
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if(l1==NULL&&l2!=NULL)
            cur->next = l2;
        else if(l1!=NULL&&l2==NULL)
            cur->next = l1;
        return head;
    }
};