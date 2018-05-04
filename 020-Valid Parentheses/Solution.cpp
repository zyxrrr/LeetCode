class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        for(int i=0;i<s.size();i++){
            if(c.empty()){
                c.push(s[i]);
            }else{
                if(match(c.top(),s[i])){c.pop();}
                else{c.push(s[i]);}
            }
        }
        if(c.empty()){return true;}
        else{return false;}
    }
    bool match(char c,char s){
        if((c=='['&&s==']')||(c=='('&&s==')')||(c=='{'&&s=='}')){return true;}
        else{return false;}
    }
};
