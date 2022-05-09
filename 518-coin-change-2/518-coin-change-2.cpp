class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        
        return countCoins(coins,amount,0,dp);
        
    }
    
    int countCoins(vector<int>& coins,int amount,int ind,vector<vector<int>>& dp){
        if(!amount)
            return 1;
        
        if(ind>=coins.size())
            return 0;
        
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        int val=0;
        
        if(amount>=coins[ind]){
            val+=countCoins(coins,amount-coins[ind],ind,dp);
        }
        
        val+=countCoins(coins,amount,ind+1,dp);
        return dp[ind][amount]=val;
    }
};