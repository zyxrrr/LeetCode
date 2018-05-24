class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> stack_idx;
        stack_idx.push(-1);
        for (int i = 0; i < s.size(); i++){
            char tmp = s[i];
           if ('(' == tmp){
               stack_idx.push(i);
           }else{
               stack_idx.pop();
               if (stack_idx.empty()){
                   stack_idx.push(i);
               }else{
                   max_len = max(max_len, i - stack_idx.top());
               }
           }
        }
        return max_len;
    }
};
