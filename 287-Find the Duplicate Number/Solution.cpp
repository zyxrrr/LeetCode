class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast != slow);
        
        int p1 = nums[0];
        int p2 = fast;
        while(p1 != p2){
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
    }
};
