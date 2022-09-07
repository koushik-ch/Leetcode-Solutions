class Solution {
public:
    
    bool memoize(string s,string p,int i,int j,vector<vector<int>>& dp){
        if(i==0&&j==0)
            return true;
        
        if(i==0)
            return dp[i][j]=p[j-1]=='*'&&memoize(s,p,i,j-1,dp);
        
        if(j==0)
            return false;
        
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(p[j-1]=='?')
            return dp[i][j]=memoize(s,p,i-1,j-1,dp);
        if(p[j-1]=='*')
            return dp[i][j]=memoize(s,p,i,j-1,dp)||memoize(s,p,i-1,j,dp);
        
        if(s[i-1]==p[j-1])
            return dp[i][j]=memoize(s,p,i-1,j-1,dp);
        
        return false;
    }
    bool isMatch(string s, string p) {
        if(p[0]!='?'&&p[0]!='*'&&p[0]!=s[0])
            return false;
        int m=s.length(),n=p.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return memoize(s,p,s.length(),p.length(),dp);
    }
};