class Solution {
public:
    
    int memoize(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(j>i)
            return INT_MAX-1;
        if(i==triangle.size()-1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int same=0,next=0;
        same=memoize(i+1,j,triangle,dp);
        next=memoize(i+1,j+1,triangle,dp);
        
        return dp[i][j]=min(same,next)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return memoize(0,0,triangle,dp);
    }
};