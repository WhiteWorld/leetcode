/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*简单递归*/
class Solution {
public:
    
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)
            return false;
        return hasPathSumHelper(root, sum);
    }
    bool hasPathSumHelper(TreeNode *root, int sum){
        if(root!=NULL && root->left != NULL && root->right != NULL){
            return hasPathSumHelper(root->left, sum-root->val) || hasPathSumHelper(root->right, sum - root->val); 
        }else if(root!=NULL && root->left != NULL)
            return hasPathSumHelper(root->left, sum-root->val);
        else if(root!=NULL && root->right != NULL)
            return hasPathSumHelper(root->right, sum-root->val);
        else if(root!=NULL)
            return sum - root->val == 0;
        else
            return false;
    }
};