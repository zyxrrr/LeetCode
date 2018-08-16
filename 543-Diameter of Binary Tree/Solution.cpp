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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root){return 0;}
        int max = 0;
        core(root, max);
        return max;
    }
    int core(TreeNode* root, int &max){
        if (root){
            int left = core(root->left,max);
            int right = core(root->right,max);
            if (left + right > max){
                max = left + right;
            }
            return 1 + (left > right ? left : right);
        }else{
            return 0;
        }
    }
};
