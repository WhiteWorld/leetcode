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
    /*暴力解法，直观但效率低*/
    bool isValidBST1(TreeNode *root) {
        if(root==NULL)
            return true;
        bool is_left = true;
        bool is_right = true;
        if(root->left)
            is_left=isValidBST(root->left) && getMax(root->left)< root->val;
        if(root->right)
            is_right=isValidBST(root->right) && getMin(root->right) > root->val;
        return is_left&&is_right;
    }
    int getMax(TreeNode *root){
        while(root->right){
            root=root->right;
        }
        return root->val;
    }
    int getMin(TreeNode *root){
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
    /*略带技巧，效率高O(N)*/
    bool isBSTHelper(TreeNode *p, int low, int high) {
      if (!p) return true;
      if (low < p->val && p->val < high)
        return isBSTHelper(p->left, low, p->val) && 
               isBSTHelper(p->right, p->val, high);
      else
        return false;
    }
     
    bool isValidBST(TreeNode *root) {
      // INT_MIN and INT_MAX are defined in C++'s <climits> library
      return isBSTHelper(root, INT_MIN, INT_MAX);  
    }
};