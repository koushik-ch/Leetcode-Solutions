class Solution {
public:
    int spaceOptimize(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        int prevSell=nums[n-1];
        int prevBuy=0;
        
        for(int i=n-1;i>=0;i--){
            //Buy
            int buyProfit;
            int sellProfit;
            
            buyProfit=-nums[i]+prevSell;
            buyProfit=max(buyProfit,prevBuy);
            prevBuy=buyProfit;
            
            sellProfit=nums[i]+prevBuy;
            sellProfit=max(sellProfit,prevSell);
            prevSell=sellProfit;
        }
        
        return prevBuy;
    }
    int tabulation(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n-1][0]=nums[n-1];
        dp[n-1][1]=0;
        
        for(int i=n-1;i>=0;i--){
            //Buy
            int buyProfit;
            int sellProfit;
            
            buyProfit=-nums[i]+dp[i+1][0];
            buyProfit=max(buyProfit,dp[i+1][1]);
            dp[i][1]=buyProfit;
            
            sellProfit=nums[i]+dp[i+1][1];
            sellProfit=max(sellProfit,dp[i+1][0]);
            dp[i][0]=sellProfit;
        }
        
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        return spaceOptimize(prices);
        return tabulation(prices);
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