class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
         vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return memoization(prices,0,1,n,dp);
    }
    
    int memoization(vector<int>& nums,int i,int buy,int n,vector<vector<int>>& dp){
        if(i==n){
            return 0;
        }
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int profit=0;
        if(buy){
            profit=-nums[i]+memoization(nums,i+1,0,n,dp);
            profit=max(profit,memoization(nums,i+1,buy,n,dp));
        }
        else{
            profit=nums[i]+memoization(nums,i+1,1,n,dp);
            profit=max(profit,memoization(nums,i+1,buy,n,dp));
        }
        return dp[i][buy]=profit;
    }
};