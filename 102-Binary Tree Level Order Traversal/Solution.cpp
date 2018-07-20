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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(NULL == root){return res;}
        
        queue<TreeNode*> q;
        q.push(root);
        int num = 0;
        int pre = 1;
        while(!q.empty()){
            vector<int> tmp;
            while(pre){
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                    num++;
                }
                if(node->right){
                    q.push(node->right);
                    num++;
                }
                pre--;
            }
            res.push_back(tmp);
            pre = num;
            num =0;
        }
        return res;
    }
};
