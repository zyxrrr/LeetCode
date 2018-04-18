class Solution {
public:
    int reverse(int x) {
        int res=0,tmp=x,i=0;
        bool minus=false;
        if(x<0){
            minus=true;
            int minus_x=-x;
            if(x+minus_x!=0){return 0;}
        }
        if(minus){x=-x;tmp=x;}
        while(x>0){        
            tmp=x%10;            
            int pre=res;
            res=res*10+tmp;
            if(res/10!=pre){return 0;}            
            x=x/10;          
        }
        return minus? -res : res;
    }
};
