/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*递归，使用map加速查询*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        if(n==0)
            return NULL;
         map<int, int> m;
         for(int i=0;i<n;i++){
             m[inorder[i]] = i;
         }
        return buildTree(inorder, 0, n-1, postorder, 0, n-1, m);
    }
    TreeNode *buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &m) {
        if(is>ie || ps > pe)
            return NULL;
        TreeNode *root=new TreeNode(postorder[pe]);
        int index=0;
        index = m[postorder[pe]];
        root->left = buildTree(inorder,is, index-1, postorder, ps, ps+index - (is+1), m);
        root->right = buildTree(inorder, index+1, ie, postorder, ps+index-is, pe-1, m);        
        return root;
    }
    
};