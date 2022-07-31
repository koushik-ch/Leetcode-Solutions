class Solution {
public:
    
    int memoize(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
       
        if(i==triangle.size()-1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int same=0,next=0;
        same=memoize(i+1,j,triangle,dp);
        next=memoize(i+1,j+1,triangle,dp);
        
        return dp[i][j]=min(same,next)+triangle[i][j];
    }
    
    int tabulation(int n,vector<vector<int>> triangle){
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
            dp[n-1][i]=triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=dp[i+1][j];
                int diagonal=dp[i+1][j+1];
                
                dp[i][j]=min(diagonal,down)+triangle[i][j];
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return tabulation(n,triangle);
        return memoize(0,0,triangle,dp);
    }
};