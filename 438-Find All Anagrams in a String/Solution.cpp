class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char, int> cnt;
        if (s.size() < p.size() || p.empty()){return res;}
        
        for (int i = 0; i < p.size(); i++){
            char key = p[i];
            cnt[key]++;
        }
        int beg = 0, end = 0, len = s.size(), counter = cnt.size();
        while (end < len){
            char tmp = s[end];
            auto it = cnt.find(tmp);
            if (it != cnt.end()){
                it->second--;
                if (it->second == 0){
                    counter--;
                }
            }
            
            end++;
            
            while(counter == 0){
                char tmp = s[beg];
                auto it = cnt.find(tmp);
                if (it != cnt.end()){
                    it->second++;
                    if (it->second > 0){
                        counter++;
                    }
                }
                
                if (end - beg == p.size()){
                    res.push_back(beg);
                }
                beg++;
            }
        }
        return res;
    }
};
