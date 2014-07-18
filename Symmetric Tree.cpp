/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 非递归思路，参考使用stack非递归进行先序遍历的方法，遍历的过程中进行比较
 */
class Solution {
public:
    /*递归解法*/
    bool isSymmetric(TreeNode *root){
        if(root == NULL)
            return true;
        return isSymmetricHelper(root->left, root->right);
    }
    bool isSymmetricHelper(TreeNode *a, TreeNode *b){
        if(a==NULL || b==NULL)
            if(a==NULL && b==NULL)
                return true;
            else
                return false;
        return isEqualNode(a, b) && isSymmetricHelper(a->left, b->right) && isSymmetricHelper(a->right, b->left);
    }
    bool isEqualNode(TreeNode *a, TreeNode *b){
        return a->val == b->val;
    }
    
};