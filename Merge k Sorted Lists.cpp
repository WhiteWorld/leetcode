#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
	 /*时间复杂度O(KN)*/
    ListNode *mergeKLists1(vector<ListNode *> &lists) {
        ListNode * ret=NULL;
        if(lists.size()==0)
            return ret;
		ret=lists[0];
		for(int i=1;i<lists.size();i++){
			bool isHead=true;
			ListNode *p=NULL;
			ListNode *head=NULL;
			int val=0;
			while(ret!=NULL||lists[i]!=NULL){
				if(ret==NULL){
					val=lists[i]->val;
					lists[i]=lists[i]->next;
				}else if(lists[i]==NULL){
					val=ret->val;
					ret=ret->next;
				}else if(ret->val > lists[i]->val){
					val=lists[i]->val;
					lists[i]=lists[i]->next;
				}else{
					val=ret->val;
					ret=ret->next;
				}
				if(isHead){
					p=new ListNode(val);
					head=p;
					isHead=false;
				}else{
					p->next = new ListNode(val);
					p=p->next;
				}
			}
			ret=head;
		}
		return ret;
    }
	
	/*最小值堆*/
	struct cmp{  
		bool operator()(ListNode * a, ListNode * b){  
			return a->val>b->val;  
		}  
	};  
	/* 使用优先队列实现，时间复杂度O（nlogK），最小值堆*/
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode* ret=NULL; 
		ListNode* cur=NULL;
		priority_queue<ListNode*,vector<ListNode* >,cmp> q;  
		if(lists.empty())
			return ret;
		for(int i=0;i<lists.size();i++)
			if(lists[i]!=NULL)  
				q.push(lists[i]);  
		bool isHead=true;
		while(!q.empty()){
			ListNode *tmpNode=q.top();
			q.pop();
			if(isHead){
				ret=tmpNode;
				cur=ret;
				isHead=false;
			}else{
				cur->next=tmpNode;
				cur=cur->next;
			}
			if(tmpNode!=NULL){
				tmpNode=tmpNode->next;
				if(tmpNode!=NULL)
					q.push(tmpNode);
			}
		}
		return ret;
	}
};
int main(){
	Solution solution;
	int t;
	cin>>t;
	vector<string> ans;
	vector<ListNode *> lists;
	ListNode *p1=new ListNode(0);
	ListNode *p2=new ListNode(2);
	ListNode *p3=new ListNode(5);
	p2->next=p3;
	p1->next=p2;
	lists.push_back(p1);
	//lists.push_back(p2);
	//lists.push_back(p3);
	ListNode *p4=solution.mergeKLists(lists);
	system("PAUSE");
	return 0;
}