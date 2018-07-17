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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack_node;
        vector<int> res;
        while(root || !stack_node.empty()){
            while(root){
                stack_node.push(root);
                root = root->left;
            }
            if(!stack_node.empty()){
                TreeNode *tmp = stack_node.top();
                stack_node.pop();
                res.push_back(tmp->val);
                root = tmp->right;
            }
        }
        return res;
    }
};
