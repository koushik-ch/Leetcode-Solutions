class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int breakPt=-1;
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakPt=i;
                break;
            }
        }
        if(breakPt<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>=breakPt;i--){
            if(nums[i]>nums[breakPt]){
                swap(nums[breakPt],nums[i]);
                break;
            }
        }
        
        reverse(nums.begin()+breakPt+1,nums.end());
    }
};