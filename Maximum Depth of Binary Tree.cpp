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
    bool is_leaf(TreeNode *root){
        return root == NULL;
    }
    int maxDepth(TreeNode *root) {
       if(is_leaf(root))
            return 0;
       else 
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};