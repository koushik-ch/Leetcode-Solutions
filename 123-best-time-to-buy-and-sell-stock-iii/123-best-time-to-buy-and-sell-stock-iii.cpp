class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return memoization(prices,0,1,0,dp);
    }
    
    int memoization(vector<int>& nums,int i,int buy,int sellCount,vector<vector<vector<int>>>& dp){
        if(i>=nums.size()||sellCount>=2)
            return false;
        if(dp[i][buy][sellCount]!=-1)
            return dp[i][buy][sellCount];
        int profit=0;
        if(buy){
            profit=-nums[i]+memoization(nums,i+1,0,sellCount,dp);
            profit=max(profit,memoization(nums,i+1,buy,sellCount,dp));
        }
        else{
            profit=nums[i]+memoization(nums,i+1,1,sellCount+1,dp);
            profit=max(profit,memoization(nums,i+1,buy,sellCount,dp));
        }
        return dp[i][buy][sellCount]=profit;
    }
};