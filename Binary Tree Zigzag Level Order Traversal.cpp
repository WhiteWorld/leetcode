/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*在queue实现的普通level遍历基础上加入reverse()即可*/
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        bool from_left=true;
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
            if(!from_left)
                std::reverse(v.begin(), v.end());
            result.push_back(v);
            from_left=!from_left;
        }
        return result;
    }
};