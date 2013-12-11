/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 注意当是第一个元素时的情况
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int cnt=0;
        ListNode *p=head;
        while(p!=NULL){
            cnt++;
            p=p->next;
        }
        n=cnt+1-n;
        p=head;
        int i=1;
        if(n==1)
            return head->next;
        while(p!=NULL){
            if(i==n-1){
                ListNode *t;
                t=p->next->next;
                p->next=t;
                break;
            }
            i++;
            p=p->next;
        }
        return head;
    }
};