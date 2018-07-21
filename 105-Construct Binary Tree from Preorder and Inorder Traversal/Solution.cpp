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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len < 1){return NULL;}
        return build(preorder, 0, len, inorder, 0, len);
    }
    TreeNode* build(vector<int>& pre, int sta_pre, int len_pre, vector<int>& in, int sta_in, int len_in){
        if(len_pre <= 0){
            return NULL;
        }
        int val = pre[sta_pre];
        int idx;
        for(int i = sta_in; i < sta_in + len_in; i++){
            if(in[i] == val){
                idx = i;
                break;
            }
        }
        int len_left = idx - sta_in;
        int len_right = len_in - len_left -1;
        TreeNode *root = new TreeNode(val);
        root->left = build(pre, sta_pre + 1, len_left, in, sta_in, len_left);
        root->right = build(pre, sta_pre + len_left + 1, len_right, in, sta_in + len_left +1, len_right);
        return root;
    }
};
