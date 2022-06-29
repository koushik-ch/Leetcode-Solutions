class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n+1,-1);
        
        return solve(nums,0,INT_MIN,dp);
    }
    
    int solve(vector<int>& nums,int ind,int prev,vector<int>& dp){
        if(ind>=nums.size()||nums[ind]<=prev)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int ans=0;
        
       for(int i=ind+1;i<=nums.size();i++){
            ans=max(ans,solve(nums,i,nums[ind],dp)+1);
            ans=max(ans,solve(nums,i,prev,dp));
       }
        return dp[ind]=ans;
    }
};