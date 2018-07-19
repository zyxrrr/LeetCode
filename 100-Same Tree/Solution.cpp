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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return core(q, p);
    }
    bool core(TreeNode* p, TreeNode* q){
        if(q && p && p->val == q->val){
            return core(p->left, q->left) && core(p->right, q->right);
        }else if(!q && !p){
            return true;
        }else{
            return false;
        }
    }
};
