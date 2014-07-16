/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*使用stack实现前序遍历：把每个遇到输出保存，把该节点右子节点入栈，然后去左子节点，如果到达空节点，则出栈作为最新节点*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> result;
        while(stack.size()!=0||root!=NULL){
            if(root == NULL){
                root = stack.top();
                stack.pop();
            }else{
                result.push_back(root->val);
                // if(root->right!=NULL) 注释掉效率降了，但是代码清晰
                stack.push(root->right);
                root = root->left;
            }
        }
        return result;
    }
};