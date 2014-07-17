/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*按照使用堆栈对二叉树进行先序遍历的思路*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        stack<TreeLinkNode *> stack;
        TreeLinkNode *head = root;
        if(head == NULL)
            return;
        stack.push(head);
        head = head->left;
        while(!stack.empty()){
            if(head!=NULL){
                if(head == stack.top()->left){
                    head->next = stack.top()->right;
                }else{
                    if(stack.top()->next)
                        head->next = stack.top()->next->left;
                    stack.pop();
                }
                stack.push(head);
                head = head->left;
            }else{
                head = stack.top()->right;
                if(head == NULL){
                    stack.pop();
                }
            }

        }
    }
};
