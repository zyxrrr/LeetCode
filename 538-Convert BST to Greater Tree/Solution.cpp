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
    TreeNode* convertBST(TreeNode* root) {
        int pre = 0;
        trans(root, pre);
        return root;
    }
    void trans(TreeNode* root, int &pre){
        if (root){
            trans(root->right, pre);
            root->val = root->val + pre;
            pre = root->val;
            trans(root->left, pre);
        }
    }
};
