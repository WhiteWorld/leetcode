/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*递归，选择中间的作为根节点*/
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        ListNode * node=head;
        while(node){
            node=node->next;
            len++;
        }
        sortedListToBST(head, 0, len-1);
        
    }
    /*强烈注意: list 是一个引用指针，会随着函数的调用改变*/
    TreeNode* sortedListToBST(ListNode *&list, int start, int end) {
        if (start > end) return NULL;
        // same as (start+end)/2, avoids overflow
        int mid = start + (end - start) / 2;
        TreeNode *leftChild = sortedListToBST(list, start, mid-1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;//重要！！！
        parent->right = sortedListToBST(list, mid+1, end);
        return parent;
    }
};