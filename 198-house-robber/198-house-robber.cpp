class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1);
        
        dp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int val1=nums[i];
            if(i>1)
                val1+=dp[i-2];
            
            dp[i]=max(val1,dp[i-1]);
        }
        return dp[nums.size()-1];
        
        return robHelper(nums,nums.size()-1);
    }
    
    int robHelper(vector<int>& nums,int ind){
        if(ind<0)
            return 0;
        
        if(ind==0)
            return nums[0];
        
        int val1=nums[ind]+robHelper(nums,ind-2);
        int val2=robHelper(nums,ind-1);
        
        return max(val1,val2);
    }
};