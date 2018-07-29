class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return sort(nums, 0 , len - 1, k);
    }
    int sort(vector<int>& nums, int sta, int end, int k){
        int mid = nums[end];
        int STA1 = sta;
        int END1 = end;
        end--;
        while(true){
            while(nums[sta] <= mid && sta < END1){
                sta++;
            }
            while(nums[end] >= mid && end > STA1){
                end--;
            }
            if(end > sta){
                swap(nums, sta, end);
            }else{
                break;
            }           
        }
        swap(nums, sta, END1);
        if(k == END1 - sta + 1){
            return nums[sta];
        }else if(k < END1 - sta + 1){
            return sort(nums, sta + 1, END1, k);
        }else{
            return sort(nums, STA1, sta - 1, k - (END1 - sta + 1));
        }
    }
    void swap(vector<int>& nums, int p1, int p2){
        int tmp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = tmp;
    }
};
