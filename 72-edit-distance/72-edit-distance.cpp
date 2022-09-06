class Solution {
public:
    int minDistance(string s1, string s2) {
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