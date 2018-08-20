class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        int nums = 0, res = 0;
        for (int i = 0; i < tasks.size(); i++){
            int tmp = tasks[i] - 'A';
            if (cnt[tmp] == 0){nums++;}
            cnt[tmp]++;
        }
        if (n <= 0 || tasks.size() < 2){return tasks.size();}
        sort(cnt.begin(), cnt.end());
        for (int i = 0; i < cnt.size(); i++){cout <<"i: "<<i << "  " <<cnt[i] << endl;}
        
        while(nums>0){
            if (nums > n){
                for (int i = 25; i > 25 - n - 1; i--){
                    //cout << "cnt[i]: " << i << " " << cnt[i] << endl;
                    res++;
                    cnt[i]--;
                    if (cnt[i] == 0){nums--;}
                }
            }else{
                int tmp = nums;
                for (int i = 25; i > 25 - tmp; i--){
                    res++;
                    //cout << "cnt[i]: " << i << " " << cnt[i] << endl;
                    cnt[i]--;
                    if (cnt[i] == 0){nums--;}
                }
                if(nums){
                    
                    res += (n - tmp + 1);
                    cout <<"    : "<< res << endl;
                }                
            }
            sort(cnt.begin(), cnt.end());
        }
        return res;
    }
};
