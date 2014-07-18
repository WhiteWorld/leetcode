/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*仔细分析一下调用的顺序，效率不低。*/
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && fabs(getDepth(root->left)-getDepth(root->right))<=1;
    }
    int getDepth(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1+max(getDepth(root->left), getDepth(root->right));
    }
    
    
};