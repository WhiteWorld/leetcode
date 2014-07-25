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
        //
        void flatten2(TreeNode *root){
            stack<TreeNode *> s;
            queue<TreeNode *> q;
            s.push(root);
            q.push(root);
            root = root->left;
            while(!s.empty()||root!=NULL){
                if(root==NULL){
                    root = s.top()->right;
                    s.pop();
                }else{
                    s.push(root);
                    q.push(root);
                    root = root->left;
                }
            }
            TreeNode * t = q.front();
            t->left = NULL;
            q.pop();
            while(!q.empty()){
                t->right = q.front();
                t = t->right;
                t->left = NULL;
                q.pop();
            }
        }
        /**/
		void flatten(TreeNode *root) {
			if(root == NULL)
				return ;
			TreeNode * tail;
			//递归
			//flatten1(root, &tail);
			flatten2(root);
		}
		void printNode(TreeNode *root){
			cout<<"node:"<<root->val<<endl;
			if(root->left)
				cout<<root->left->val<<endl;
			else
				cout<<"#"<<endl;
			if(root->right)
				cout<<root->right->val<<endl;
			else
				cout<<"#"<<endl;
			
		}
		void flatten1(TreeNode *head, TreeNode **tail){
			if(head->left == NULL && head->right == NULL){
				*tail = head;
			}
			else if(head->left == NULL){
				flatten1(head->right, tail);
			}else if(head->right == NULL){
				head->right = head->left;
				head->left = NULL;
				flatten1(head->right, tail);
			}else{
				TreeNode * right = head->right;
				head->right = head->left;
				TreeNode *tnode=head->left;
				while(tnode->right){
					tnode = tnode->right;
				}
				tnode->right = right;
				flatten1(head->right, tail);
				head->left = NULL;
			}
		}
};