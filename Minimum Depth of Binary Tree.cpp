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
    /*队列：MLE*/
    int minDepth(TreeNode *root) {
        queue<TreeNode *> q;
        if(root==NULL)
            return 0;
        int dep=1;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            root = q.front();
            if(root!=NULL){
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                if(root->left==NULL && root->right==NULL){
                    while(!q.empty())
                        q.pop();
                    return dep;
                }
            }else{
                dep++;
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
        }
    }
    /*递归*/
    int minDepth2(TreeNode *root){
        if(root==NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left == NULL)
            return 1 + minDepth(root->right);
        if(root->right == NULL)
            return 1+ minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
};