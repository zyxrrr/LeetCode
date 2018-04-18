class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){return s;}
        vector<string> str(numRows);
        int j=0;
        bool flag=true;
        for(int i=0;i<s.size();i++){
            if(flag){
                str[j]+=s[i];
                j++;
                if(j==numRows){
                    j=numRows-2;flag=false;
                }
            }else{
                str[j]+=s[i];
                j--;
                if(j==-1){
                    j=1;flag=true;
                }
            }
            //str
        }
        string res;
        for(j=0;j<numRows;j++){
            res+=str[j];
        }
        return res;
    }
};
