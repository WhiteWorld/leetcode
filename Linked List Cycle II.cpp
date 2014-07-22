/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*参见Linked List Cycle 1*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        return !(fast == NULL || fast->next == NULL);
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        ListNode *meetp = slow;
        ListNode *start = head;
        while(meetp!=start){
            meetp = meetp->next;
            start = start->next;
        }
        return start;
    }
};