/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*使用stack实现中序遍历：把遇到的每个节点入栈，去左子节点，如果到达空节点，则输出栈顶元素并把出栈的节点的右节点作为新的节点*/
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> result;
        while(!s.empty()||root){
            if(root==NULL){
                root = s.top();
                result.push_back(root->val);
                root = root->right;
                s.pop();
            }else{
                s.push(root);
                root = root->left;
            }
        }
        return result;
    }
};