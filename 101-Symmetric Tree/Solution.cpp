/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){return true;}
        return core(root->left, root->right);
    }
    
    bool core(TreeNode* L, TreeNode* R){
        if(L && R && L->val == R->val){
            return (core(L->left, R->right) && core(L->right, R->left));
        }else if(!L && !R){
            return true;
        }else{
            return false;
        }        
    }
  
};
