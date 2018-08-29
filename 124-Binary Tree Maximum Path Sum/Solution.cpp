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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        travel(root, res);
        return res;
    }
    void travel(TreeNode* root, int &res){
        if (root){
            travel(root->left, res);
            travel(root->right, res);
            if (root->left && root->left->val > 0 && root->right && root->right->val > 0){
                int tmp = root->val + root->left->val + root->right->val;
                res = max(res, tmp);
                int max_ = max(root->left->val, root->right->val);
                root->val += max_;
            }else if (root->right && root->right->val > 0){
                root->val += root->right->val;
                res = max(res, root->val);
            }else if (root->left && root->left->val > 0){
                root->val += root->left->val;
                res = max(res, root->val);
            }else{
                res = max(res, root->val);
            }            
        }
    }
};
