class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        ans[1] = 1;
        int pre = 2, now = 2;
        for (int i = 2; i <= num; i++){
            if (i == now){
                ans[i] = 1;
                pre = now;
                now = 2*pre;
            }
            else{
                //cout << "i: " << i << "pre: "<<pre<<endl;
                ans[i] = ans[pre] + ans[i-pre];
            }
        }
        return ans;
    }
};
