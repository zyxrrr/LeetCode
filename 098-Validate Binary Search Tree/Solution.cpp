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
    bool isValidBST(TreeNode* root) {
        bool res = core(root, NULL, NULL);
        return res;
    }
    bool core(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root){
            return true;
        }else{
            int val = root->val;
            if((min && val <= min->val) || (max && val >= max->val)){
                return false;
            }else{
                return core(root->left, min, root) && core(root->right, root, max);
            }
        }        
    }
};
