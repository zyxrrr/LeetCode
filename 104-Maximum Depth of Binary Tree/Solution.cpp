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
    int maxDepth(TreeNode* root) {
        return maxDep(root);
    }
    int maxDep(TreeNode* root){
        if(NULL == root){
            return 0;
        }else{
            return max(maxDep(root->left), maxDep(root->right)) + 1;
        }
    }
};
