#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printLink(ListNode*head){
	while(head){
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<endl;
}
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int length = 0;
        ListNode *p=head;
        while(p){
            p = p->next;
            length++;
        }
        cout<<"length:"<<length<<endl;
        if(length<2)
            return head;
        if(length==2){
            if(head->val<=head->next->val)
                return head;
            else{
                ListNode *t=head->next;
                head->next=NULL;
                t->next=head;
                return t;
            }
        }
        int cnt=0;
        p=head;
        while(cnt<length/2){
            p=p->next;
            cnt++;
        }
        ListNode *first = head;
        ListNode *second = p->next;
        p->next = NULL;
        printLink(first);
        printLink(second);
        first=sortList(first);
        second=sortList(second);
        printLink(first);
        printLink(second);
        return mergeSortedList1(first,second);
    }
	/*递归版本*/
    ListNode *mergeSortedList(ListNode *first,ListNode *second){
    	cout<<"merge"<<endl;
    	printLink(first);
    	printLink(second);
    	if(first == NULL && second == NULL)
    		return NULL;
        if(first == NULL)
        	return second;
        if(second == NULL)
        	return first;
        if(first->val < second->val){
        	first->next = mergeSortedList(first->next, second);
        	return first;
        }else{
        	second->next = mergeSortedList(first, second->next);
        	return second;
        }
    }
    /*O(n)版本*/
    ListNode *mergeSortedList1(ListNode *first,ListNode*second){
    	ListNode *cur ,*head;
    	cur = NULL;
    	head = NULL;
    	while(first!=NULL&&second!=NULL){
    		if(first->val < second->val){
    			if(cur==NULL){
    				head = first;
    				cur = first;
    			}else{
    				cur->next = first;
    				cur = cur->next;
    			}
    			first = first->next;
    		}else{
    			if(cur==NULL){
    				head = second;
    				cur = second;
    			}else{
    				cur->next = second;
    				cur = cur->next;
    			}
    			second = second->next;    			
    		}
    	}
    	if(first==NULL&&second==NULL){
    		if(cur == NULL){
    			head = first;
    		}else{
    			cur->next = NULL;
    		}

    	}else if(first == NULL){
    		if(cur == NULL)
    			head = second;
    		else
    			cur->next = second;
    	}else if(second == NULL){
    		if(cur == NULL)
    			head = first;
    		else
    			cur->next = first;
    	}
    	return head;
    }
};

int main(){
	Solution s;
	ListNode *head = new ListNode(7);
	ListNode *p=head;

	head->next = new ListNode(6);
	head = head->next;

	head->next = new ListNode(5);
	head = head->next;

	head->next = new ListNode(4);
	head = head->next;

	head->next = new ListNode(5);
	head = head->next;

	head->next = new ListNode(6);
	head = head->next;

	head->next = new ListNode(7);
	printLink(p);
	p = s.sortList(p);
	printLink(p);
	return 0;
}
