class Solution {
public:
    string decodeString(string s) {
        if (s.empty()){return s;}
        stack <int> times;
        stack <string> sub_s;
        sub_s.push("");
        string ans;
        string sub_tmp;
        bool sta = true;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            
                if (c >= '0' && c <= '9'){
                    cnt = 10 * cnt + c - '0';
                }
                if (c == '['){
                    times.push(cnt);
                    cnt = 0;
                    sub_s.push("");
                }
                if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                    string sub_tmp = sub_s.top();
                    sub_tmp += c;
                    sub_s.pop();
                    sub_s.push(sub_tmp);                    
                }
                if (c == ']'){
                    string tmp = sub_s.top();
                    sub_s.pop();
                    int s_times = times.top();
                    times.pop();
                    for (int j = 0; j < s_times; j++){
                        ans += tmp;
                        //cout << j << endl;
                    }
                    tmp = sub_s.top();
                    sub_s.pop();
                    sub_s.push(tmp + ans);
                    ans.clear();
                }
            
        }       
        ans = sub_s.top();
        return ans;
    }
};
