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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s && t){
            if (equal(s, t)){return true;}
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }else{
            return false;
        }                  
    }
    bool equal(TreeNode* s, TreeNode* t){
        if (!s && !t){
            return true;
        }else if (s && t && s->val == t->val){
            return equal(s->left, t->left) && equal(s->right, t->right);
        }else{
            return false;
        }
    }
};
