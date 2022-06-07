class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n-1;
        int ind1=m-1;
        int ind2=n-1;
        
        while(ind1>=0&&ind2>=0){
            if(nums1[ind1]>nums2[ind2]){
                nums1[i]=nums1[ind1];
                i--;
                ind1--;
            }else{
                nums1[i]=nums2[ind2];
                i--;
                ind2--;
            }
        }
        cout<<i;
       while(ind2>=0){
           nums1[i]=nums2[ind2];
           i--;
           ind2--;
       }
    }
};