/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*一个慢指针，一个快指针，如果有环最终会相遇
问题：
1、如何判断一个链表是不是这类链表？
2、如果链表为存在环，如何找到环的入口点？
答：
1. 设置两个指针(fast, slow)，初始值都指向头，slow每次前进一步，fast每次前进二步，如果链表存在环，则fast必定先进入环，而slow后进入环，两个指针必定相遇。
2. 链表头、与相遇点分别设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。

扩展问题：

判断两个单链表是否相交，如果相交，给出相交的第一个点（两个链表都不存在环）。

比较好的方法有两个：

一、将其中一个链表首尾相连，检测另外一个链表是否存在环，如果存在，则两个链表相交，而检测出来的依赖环入口即为相交的第一个点。

二、如果两个链表相交，那个两个链表从相交点到链表结束都是相同的节点，我们可以先遍历一个链表，直到尾部，再遍历另外一个链表，如果也可以走到同样的结尾点，则两个链表相交。

这时我们记下两个链表length，再遍历一次，长链表节点先出发前进(lengthMax-lengthMin)步，之后两个链表同时前进，每次一步，相遇的第一点即为两个链表相交的第一个点。


 */
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
};