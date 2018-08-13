class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.empty() || s.empty() || p.size() > s.size()){return res;}
        int a[128] = {0};
        int o[129] = {0};
        for (int i = 0; i < p.size(); i++){
            int idx = p[i] - '0';
            a[idx]++;
            o[idx]++;
        }
        for (int i = 0; i < s.size() - p.size() + 1; i++){
            bool flag = true;
            for (int j = 0; j < p.size(); j++){
                int idx = s[i+j] - '0';
                //cout << s[i+j] << endl;
                //cout << idx <<endl;
                if (a[idx] > 0){
                    a[idx]--;
                }else{
                    flag = false;
                    break;
                }
            }
            if (flag){
                res.push_back(i);
            }
            for (int i = 0; i < 128; i++){
                
                a[i] = o[i];
                
            }
        }
        return res;
    }
};
