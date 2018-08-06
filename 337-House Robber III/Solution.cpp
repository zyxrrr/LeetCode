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
    int rob(TreeNode* root) {
        vector<int> res = rob_house(root);
        return max(res[0], res[1]);
    }
    vector<int> rob_house(TreeNode *root){
        vector<int> res(2,0);
        if (root){
            vector<int> left = rob_house(root->left);
            vector<int> right = rob_house(root->right);
            res[0] = max(left[0], left[1]) + max(right[0], right[1]);
            res[1] = root->val + left[0] + right[0];            
        }
        return res;
    }
};
