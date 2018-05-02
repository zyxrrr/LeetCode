class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,max_area=0,l_,r_;
        while(l<r){
            l_=height[l];
            r_=height[r];
            if((r-l)*min(l_,r_)>max_area){
                max_area=(r-l)*min(l_,r_);
            }
            if(l_>r_){
                r--;
            }else{
                l++;
            }
            //max_area=(max_area>(r-l)*min(l_,r_))?max_area:
        }
        return max_area;
    }
};
