class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=triangle.size();
        int j=triangle[i-1].size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        
        
        return solve(triangle,0,0,dp);
        
    }
    
    int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        if(i>=triangle.size())
            return 0;
        
        if(j>=triangle[i].size())
            return INT_MAX;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=min(solve(triangle,i+1,j,dp),solve(triangle,i+1,j+1,dp))+triangle[i][j];
        
    }
};