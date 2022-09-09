class Solution {
public:
    int memoization(vector<int>& nums,int i,int prevInd,vector<vector<int>>& dp){
        if(i==nums.size())
            return 0;
        
        if(dp[i][prevInd+1]!=-1)
            return dp[i][prevInd+1];
        
        int notTake=memoization(nums,i+1,prevInd,dp);
        int take=0;
        
        if(prevInd==-1||nums[i]>nums[prevInd])
            take=memoization(nums,i+1,i,dp)+1;
        
        
        return dp[i][prevInd+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return memoization(nums,0,-1,dp);
    }
    
};