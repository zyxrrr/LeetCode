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
        if (root){
            int cnt1 = root->val + rob_house(root->left, false) + rob_house(root->right, false);
            int cnt2 = rob_house(root->left, true) + rob_house(root->right, true);
            return max(cnt1, cnt2);
        }else{
            return 0;
        }        
    }
    int rob_house(TreeNode *root, bool can_rob){
        if (root){
            if (can_rob){
                int cnt1 = root->val + rob_house(root->left, false) + rob_house(root->right, false);
                int cnt2 = rob_house(root->left, true) + rob_house(root->right, true);
                return max(cnt1, cnt2);
            }else{
                int cnt2 = rob_house(root->left, true) + rob_house(root->right, true);
                return cnt2;
            }
        }else{
            return 0;
        }
    }
};
