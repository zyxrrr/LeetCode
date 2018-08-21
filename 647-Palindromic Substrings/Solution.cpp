class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, left, right;
        for (int i = 1; i <= s.size() - 1; i++){
            left = i - 1;
            right = i + 1;
            while(left >= 0 && right < s.size() ){
                if (s[left] == s[right]){
                    res++;
                }else{
                    break;
                }
                left--;
                right++;
            }
            left = i - 1;
            right = i;
            while(left >= 0 && right < s.size() ){
                if (s[left] == s[right]){
                    res++;
                }else{
                    break;
                }
                left--;
                right++;
            }
        }
        return res + s.size();
    }
};
