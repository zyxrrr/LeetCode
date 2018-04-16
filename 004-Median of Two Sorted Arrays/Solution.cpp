class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int>& list1=nums1,list2=nums2;//list2 is longer than list1
        if(len1>len2){
            list2=nums1;list1=nums2;
            int tmp=len1;
            len1=len2;len2=tmp;
        }
        int i=0,i_min=0,i_max=len1,half_len=(len1+len2+1)/2,j,max_left,min_right;
        //if(len1==0){
          //  return len2%2==0 ? (list2[len2/2]+list2[len2/2-1])/2 : list2[len2/2];
        //}
        while(i_min<=i_max){
            i=(i_min+i_max)/2;
            j=half_len-i;
            if(i>0 && list1[i-1]>list2[j]){
                i_max=i-1;
            }else if(i<len1 && list2[j-1]>list1[i]){
                i_min=i+1;
            }else{
                //(list1[i-1]<=list2[j] && list2[j-1]<=list1[i]){
                if(i==0){
                    max_left=list2[j-1];
                   // return (len1+len2)%2==0 ? (list2[j]+list2[j-1])/2.0 : list2[j];
                }else if(j==0){
                    max_left=list1[i-1];
                }else{
                    max_left=max(list1[i-1],list2[j-1]);
                }
                
                if((len1+len2)%2==1){return max_left;}
                
                if(i==len1){
                    min_right=list2[j];
                }else if(j==len2){
                    min_right=list1[i];
                }else{
                    min_right=min(list1[i],list2[j]);
                }
                
                return (max_left+min_right)/2.0;
                //break;
            }
            
        }
        //return (len1+len2)%2==0 ? (list1[i]+list2[j])/2.0 : max(list1[i],list2[j]);
    }
};
