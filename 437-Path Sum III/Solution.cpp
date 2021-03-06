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
    int pathSum(TreeNode* root, int sum) {
        if (!root){return 0;}
        return pathFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int pathFrom(TreeNode* root, int sum){
        if (!root){return 0;}
        return (root->val == sum ? 1 : 0) + pathFrom(root->left, sum - root->val) + pathFrom(root->right, sum - root->val);
    }
};
