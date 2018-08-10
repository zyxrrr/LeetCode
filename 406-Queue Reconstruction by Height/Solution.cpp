class Solution {
public:
     bool static cmp(const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int> > res;
        for (auto &tmp : people){
            res.insert(res.begin() + tmp.second, tmp);
        }
        return res;
    }
    
   
};
