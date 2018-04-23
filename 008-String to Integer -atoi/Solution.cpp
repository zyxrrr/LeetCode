class Solution {
public:
    int myAtoi(string str) {
        int len=str.size(),i=0,res=0,pre;
        bool minus=false;        
        if(len<1){return 0;}
        for(i=0;i<len;i++){
            if(str[i]!=' '){break;}
        }
        if(i<len && str[i]=='-'){
            minus=true;
            i++;
        }else if(i<len && str[i]=='+'){
            i++;
        }else if(i<len && (str[i]<'0' || str[i]>'9')){
            return 0;
        }        
        for(;i<len;i++){
            if(str[i]>='0'&&str[i]<='9'){
                if(minus){
                    pre=res;
                    res=res*10-(str[i]-'0');
                    if(res/10!=pre){res=INT_MIN;break;}
                }else{
                    pre=res;
                    res=res*10+(str[i]-'0');
                    if(res/10!=pre){res=INT_MAX;break;}
                }
                
            }else{
                //res=0;
                break;
            }
        }
        return res;
    }
};
