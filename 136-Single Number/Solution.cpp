class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        map<int ,int> hash;
        for(int i = 0; i < nums.size(); i++){
            if(hash.find(nums[i]) == hash.end()){
                hash[nums[i]] = i;
            }else{
                map<int, int>::iterator it = hash.find(nums[i]);
                hash.erase(it);
            }
        }
        map<int, int>::iterator it = hash.begin();
        return it->first;
        */
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = res ^ nums[i];
        }
        return res;
    }
};
