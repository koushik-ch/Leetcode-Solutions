class Solution {
public:
    int spaceOptimize(string s1,string s2){
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m+1,0);

        for(int j=0;j<m;j++)
            prev[j]=j;

        for(int i=1;i<n+1;i++){
            vector<int> curr(m+1,0);
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j]=prev[j-1];

                else curr[j] = 1+min(prev[j-1],min(prev[j],curr[j-1]));
            }
            prev=curr;
        }

        return prev[m];
    }
        
    int tabulation(string S1,string S2){
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
        
    }
    int minDistance(string s1, string s2) {
        return tabulation(s1,s2);
        
        int n=s2.length();
        int m=s1.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return recurse(s1,s2,m,n,dp);
    }
    
    int recurse(string s1,string s2,int i,int j,vector<vector<int>>& dp){
        if(i==0)
            return dp[i][j]=j;
        if(j==0)
            return dp[i][j]=i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i-1]==s2[j-1])
            return recurse(s1,s2,i-1,j-1,dp);
        
        int ins=recurse(s1,s2,i,j-1,dp)+1;
        int del=recurse(s1,s2,i-1,j,dp)+1;
        int rep=recurse(s1,s2,i-1,j-1,dp)+1;
        
        return dp[i][j]=min(ins,min(del,rep));
    }
    
    
};