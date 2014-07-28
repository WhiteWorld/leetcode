/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*递归*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root;
        int n = preorder.size();
        if(n==0)
            return NULL;
        return buildTree(preorder, 0, n-1, inorder, 0, n-1);
    }
    TreeNode *buildTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is,int ie) {
        if(ps>pe || is>ie)
            return NULL;
        TreeNode*root = new TreeNode(preorder[ps]);
        int index = -1;
        for(int i=is;i<=ie;i++)
            if(inorder[i]==preorder[ps]){
                index=i;
                break;
            }
        root->left = buildTree(preorder, ps+1, ps+(index-is), inorder,is, index-1);
        root->right = buildTree(preorder, pe-(ie-index-1), pe, inorder,index+1, ie);
        return root;
    }
    
};