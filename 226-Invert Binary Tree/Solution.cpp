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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    void invert(TreeNode* root){
        if (root){
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invert(root->left);
            invert(root->right);
        }else{
            return;
        }
    }
};
