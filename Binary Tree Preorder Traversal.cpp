/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*使用stack实现前序遍历：把每个遇到的非空节点保存，把非空右子节点入栈，如果到达最左边的节点，则出栈作为最新节点*/
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
                if(root->right!=NULL)
                    stack.push(root->right);
                root = root->left;
            }
        }
        return result;
    }
};