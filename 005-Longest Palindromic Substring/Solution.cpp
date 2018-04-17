class Solution {
public:
    string longestPalindrome(string s) {
        int sta=0,end=0;
        for(int i=0;i<s.size();i++){
            int len1=lengthMax(s,i,i);
            int len2=lengthMax(s,i,i+1);
            int len=max(len1,len2);
            if(len>=end-sta+1){
                sta=i-(len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(sta,end-sta+1);
    }
    int lengthMax(string& s,int l,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;r++;
        }
        l++;r--;
        return r-l+1;
    }
};
