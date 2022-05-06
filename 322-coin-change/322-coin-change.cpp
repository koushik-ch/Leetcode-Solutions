class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());//
        int n=coins.size();
        
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        
        int val=coinChange(coins,0,amount,0,dp);
        
        if(val==INT_MAX-1)
            return -1;
        return val;
    }
        
    int coinChange(vector<int>& coins,int ind,int amount,int count,vector<vector<int>>& dp){
        
        if(ind>=coins.size()){
            return INT_MAX-1;
        }
        
        if(!amount){
            return 0;
        }
        
        else if(coins[ind]>amount)
            return coinChange(coins,ind+1,amount,count,dp);
        
        if(dp[amount][ind]!=-1)
            return dp[amount][ind];
            
        int pickAgain=1+coinChange(coins,ind,amount-coins[ind],count+1,dp);
        
        int pick=1+coinChange(coins,ind+1,amount-coins[ind],count+1,dp);
        
        int nonPick=coinChange(coins,ind+1,amount,count,dp);
        
        return dp[amount][ind]=min(pick,min(pickAgain,nonPick));
        
    }
};