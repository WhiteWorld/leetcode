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
    ListNode *rotateRight(ListNode *head, int k) {
        int len;
        ListNode * t=head;
        ListNode *tail;
        ListNode *result;
        len=0;
        while(t!=NULL){
            len++;
            tail=t;
            t=t->next;
        }
        if(len==0)
            return head;
        k=k%len;// mod the length of list
        if(k==0)
            return head;
        t=head;
        int cnt=1;
        while(t!=NULL){
            if(cnt==(len-k)){
                result=t->next;
                t->next=NULL;
                break;
            }else{
                cnt++;
                t=t->next;
            }
        }
        tail->next=head;//
        return result;
    }
};