/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*DFS 深度遍历  vector 保存路径， 注意节点的值有可能为负*/
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if(root==NULL)
            return result;
        vector<int> path;
        dfs(root, sum, path, result);
        return result;
    }
    bool is_leaf(TreeNode *root){
        return root->left==NULL && root->right==NULL;
    }
    void dfs(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &result){
        if(is_leaf(root)){
            if(sum == root->val){
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
            }
        }else if(root->left==NULL){
            path.push_back(root->val);
            dfs(root->right, sum-root->val, path, result);
            path.pop_back();
        }else if(root->right==NULL){
            path.push_back(root->val);
            dfs(root->left, sum-root->val, path, result);
            path.pop_back();
        }else{
            path.push_back(root->val);
            dfs(root->left, sum-root->val, path, result);
            dfs(root->right, sum-root->val, path, result);
            path.pop_back();
        }
    }
};