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
    /*使用prev指针记录上次经过的node*/
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
  stack<TreeNode*> s;
  s.push(root);
  TreeNode *prev = NULL;
  while (!s.empty()) {
    TreeNode *curr = s.top();
    // we are traversing down the tree
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left) {
        s.push(curr->left);
      } else if (curr->right) {
        s.push(curr->right);
      } else {
         result.push_back(curr->val);
        s.pop();
      }
    } 
    // we are traversing up the tree from the left
    else if (curr->left == prev) {
      if (curr->right) {
        s.push(curr->right);
      } else {
        result.push_back(curr->val);
        s.pop();
      }
    }
    // we are traversing up the tree from the right
    else if (curr->right == prev) {
      result.push_back(curr->val);
      s.pop();
    }
    prev = curr;  // record previously traversed node
  }
  return result;
}
    
};