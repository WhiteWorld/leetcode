/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
/*两个指针，间隔为1，一步一步往前推进，如果值相等，则删除前面的指针，不想等则往前推进*/
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *first=head,*second=head;
        if(head == NULL)
            return head;
        first = first->next;
        while(first != NULL){
            if(first->val == second->val){
                second->next = first->next;
                first = first->next;
            }else{
                second = first;
                first = first->next;
            }
        }
        return head;
    }
    /*上面的想法复杂了，一个指针就好啦*/
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};