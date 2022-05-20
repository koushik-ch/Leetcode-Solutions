class Solution {
public:
    int m,n;
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return countPaths(grid,0,0,dp);
    }
    
    int countPaths(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=0)
            return 0;
        
        if(i==m-1&&j==n-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j]; 
        
       dp[i][j]=countPaths(grid,i+1,j,dp)+countPaths(grid,i,j+1,dp);
        
        return dp[i][j];
    }
};