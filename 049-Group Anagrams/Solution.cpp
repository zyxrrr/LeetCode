class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > res;
        for(int i = 0; i < strs.size(); i++){
            string str = strs[i];
            /*
            int key[26] = {0};
            for(int j = 0; j < str.size(); j++){
                int tmp = str[j] - 'a';
                key[tmp]++;
            }
            */
            sort(str.begin(), str.end());
            res[str].push_back(strs[i]);            
        }
        vector<vector<string> > ans;
        for(unordered_map<string, vector<string> >::iterator iter = res.begin(); iter != res.end(); iter++){
            ans.push_back(iter->second);
        }
        /*
        for(int i = 0; i < res.size(); i++){
            ans.push_back(res[i].second);
        }
        */
        return ans;
    }
};
