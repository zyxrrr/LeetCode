class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        vector<int> tmp(256,-1);
        int len=s.size();
        int sta=0,end=0,max=0,count=0;        
        while(end<len){
            char c=s[end];
            if(hash[c-0]==-1){
                count=end-sta+1;
                max=count>max?count:max;
                hash[c-0]=end;
                end++;
            }else{                
                sta=hash[c-0]+1;
                hash=tmp;
                for(int i=sta;i<=end;i++){
                    hash[s[i]-0]=i;
                }
                count=end-sta+1;
                end++;
            }            
        }
        return max;
    }
};
