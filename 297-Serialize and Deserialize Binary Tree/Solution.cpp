/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        core(root, res);
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> node;
        int l = 0,r;
        for (int i = 0; i < data.size(); i++){
            if (data[i] == ','){
                r = i;
                node.push_back(data.substr(l, r-l));
                l = r+1;
            }
        }
        TreeNode *root = NULL;
        if (node[0] != "n"){
            root = new TreeNode(str2num(node[0]));
        }else{
            root = NULL;
        }
        queue<TreeNode* > q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < node.size()){
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp){
                tmp->left = str2node(node[i]);
                i++;
                q.push(tmp->left);
                tmp->right = str2node(node[i]);
                q.push(tmp->right);
                i++;
            }
            
        }
        return root;
        /*
        for (int i = 1; i < node.size(); i++){
            TreeNode *tmp = q.top();
            q.pop();
            tmp->left = str2node(node[i]);
            i++;
            q.push(tmp->left);
            tmp->right = str2node(node[i]);
            q.push
        }*/
    }
    
    TreeNode* str2node(string s){
        if (s != "n"){
            TreeNode *tmp = new TreeNode(str2num(s));
            return tmp;
        }else{
            return NULL;
        }
    }
    
    void core(TreeNode* root, string &res){
        queue<TreeNode* > q;
        if (root){
            q.push(root);
        }else{
            q.push(NULL);
        }
        while (!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp){
                res += to_string(tmp-> val);
                q.push(tmp->left);
                q.push(tmp->right);
            }else{
                res += "n";
            }
            res += ",";
        }
    }
    
    int str2num(string s){
        bool minus = false;
        int res = 0, i = 0;
        if (s[0] == '-'){
            minus = true;
            i = 1;
        }
        for (; i < s.size(); i++){
            res = (s[i] - '0') + res * 10;
        }
        return minus ? -res : res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
