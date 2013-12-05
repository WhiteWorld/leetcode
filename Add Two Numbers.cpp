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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result;//result point for return
        ListNode *cur;
        int flag=0;
        int head=1;
        while(l1!=NULL||l2!=NULL){
            int sum;
            sum=0;
            if(l1==NULL){
                sum=l2->val+flag;
                l2=l2->next;
            }else if(l2==NULL){
                sum=l1->val+flag;
                l1=l1->next;
            }else{
                sum=l1->val+l2->val+flag;
                l1=l1->next;
                l2=l2->next;
            }
            if(sum>9){
                sum-=10;
                flag=1;
            }else
                flag=0;

            if(head){//保存第一个节点
                cur= new ListNode(sum);
                result=cur;
				head = 0;
            }else{
                cur->next=new ListNode(sum);
                cur=cur->next;
            }
        }
        if(flag){
            cur->next=new ListNode(1);
        }
        return result;
    }
    
};