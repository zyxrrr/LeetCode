class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s=s.size(),len_p=p.size();
        if(len_p==0){return len_s==0;}
        
        bool first=len_s!=0 && (s[0]==p[0]||p[0]=='.');
        
        if(len_p>=2 && p[1]=='*'){
            return (first&&isMatch(s.substr(1),p))
                ||isMatch(s,p.substr(2));
        }else{
            return first
                &&isMatch(s.substr(1),p.substr(1));
        }
    }
};
