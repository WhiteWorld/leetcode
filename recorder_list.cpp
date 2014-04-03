#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
/*
 *链表从中间分开，反转其中一个，然后再合并
 * */
class Solution {
	public:
		void reorderList(ListNode *head) {
			if(head == NULL)
				return;
			ListNode *p = head;
			ListNode *tp = head;
			while(tp->next != NULL)
				tp = tp->next;

			return myorder(p, tp);
		}
		void myorder(ListNode *head, ListNode *tail){
			if(head == tail)
				return;
			if(head->next == tail)
				return;
			ListNode *p;
			p = head->next;
			head->next = tail;
			tail->next = p;
			head = p;
			while(p->next != tail)
				p = p->next;
			p->next = NULL;
			tail = p;
			return myorder(head, tail);
		}
};
int main(){
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *p;
	p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	s.reorderList(head);
	while(head != NULL)
	{
		cout<<head->val<<endl;
		head = head->next;
	}
	return 0;
}
