class Solution {
public:
    int mod = pow(10,9) + 7;
    int findPaths(int m, int n, int N, int i, int j) {
        
       vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        
        return solve(m,n,i,j,N,dp);
    }
    
    int solve(int m,int n,int i,int j,int N,vector<vector<vector<int>>>& dp){
        
        if(i<0||j<0||i>=m||j>=n)
            return 1;
        
        if(N==0)
            return 0;
        
        if(dp[N][i][j]!=-1)
            return dp[N][i][j];
        
        int temp=0;
      temp=(temp+solve(m,n,i-1,j,N-1,dp))%mod;
        temp=(temp+solve(m,n,i+1,j,N-1,dp))%mod;
        temp=(temp+solve(m,n,i,j+1,N-1,dp))%mod;
        temp=(temp+solve(m,n,i,j-1,N-1,dp))%mod;
        
        return dp[N][i][j]=(temp)%mod;
        
        
    }
    
};