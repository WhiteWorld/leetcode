/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*队列中序遍历，顺便设置next指针*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            if(root->right)
                q.push(root->right);
            if(root->left)
                q.push(root->left);
            if(root->left){
                if(root->right)
                    root->left->next = root->right;
                else{
                    TreeLinkNode * tnode = root->next;
                    while(tnode){
                        if(tnode->left){
                            root->left->next = tnode->left;
                            break;
                        }
                        else if(tnode->right){
                            root->left->next = tnode->right;
                            break;
                        }
                        else
                            tnode = tnode->next;
                    }
                }
            }
            if(root->right){
                    TreeLinkNode * tnode = root->next;
                    while(tnode){
                        if(tnode->left){
                            root->right->next = tnode->left;
                            break;
                        }
                        else if(tnode->right){
                            root->right->next = tnode->right;
                            break;
                        }
                        else
                            tnode = tnode->next;
                    }
            }
            q.pop();
        }
    }

};