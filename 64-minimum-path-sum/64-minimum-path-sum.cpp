class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return memoize(m-1,n-1,m,n,grid,dp);
       
    }
    
    int memoize(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i<0||j<0||i>=m||j>=n)
        return INT_MAX-1;
    if(i==0&&j==0)
        return grid[0][0];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int left=memoize(i,j-1,m,n,grid,dp);
    int up=memoize(i-1,j,m,n,grid,dp);
    int val=min(left,up);
    
    return dp[i][j]=val+grid[i][j];
    
}
};