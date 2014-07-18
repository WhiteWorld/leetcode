/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*递归解法，取中间点作为新的root*/
class Solution {
public:
    TreeNode *sortedArrayToBSTHelper(vector<int> &num, int start, int end){
        if(start > end)
            return NULL;
        if(start == end){
            return new TreeNode(num[start]);
        }
        int root = (start+end)/2;
        TreeNode *p = new TreeNode(num[root]);
        p->left = sortedArrayToBSTHelper(num, start, root-1);
        p->right = sortedArrayToBSTHelper(num, root+1, end);
        return p;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size()==0)
            return NULL;
        return sortedArrayToBSTHelper(num,0,num.size()-1);
    }

};