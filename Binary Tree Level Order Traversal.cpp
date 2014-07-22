/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*使用队列，保存上一级的节点*/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            vector<int> v;
            while(q.front()!=NULL){
                root = q.front();
                q.pop();
                v.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            q.pop();
            if(!q.empty())
                q.push(NULL);
            result.push_back(v);
        }
        return result;
    }
};