/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*prev指针是关键*/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
         if(head==NULL)
            return head;
         if(head->next==NULL)
            return head;
         if(m==n)
            return head;
         ListNode* node = new ListNode(0);
         node->next = head;
         ListNode* cur=head;
         ListNode* pre = node;
         
         ListNode* mpre,*mpos;
         int pos=1;
         while(cur){
             if(pos == m){
                 mpre = pre;
                 mpos = cur;
                 break;
             }
             cur = cur->next;
             pre = pre->next;
             pos++;
         }
         pos=m+1;
         cur=mpos->next;
         pre = mpos;
         while(pos<=n){
             ListNode* t = mpos->next;
             mpos->next = mpos->next->next;
             
             t->next = mpre->next;
             mpre->next = t;
             pos++;
         }
         return node->next;
    }
};