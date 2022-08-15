class Solution {
public:
    
    int memoize(int ind1,int ind2,string s1,string s2,vector<vector<int>>& dp){
        if(ind1<0||ind2<0)
            return 0;
        
        if(ind1==0&&ind2==0)
            return s1[ind1]==s2[ind2];
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])
            return dp[ind1][ind2]=memoize(ind1-1,ind2-1,s1,s2,dp)+1;
        
        return dp[ind1][ind2]=max(memoize(ind1-1,ind2,s1,s2,dp),memoize(ind1,ind2-1,s1,s2,dp));
        
    }
    
    int tabulation(int m1,int m2,string s1,string s2){
        vector<vector<int>> dp(m1+1,vector<int>(m2+1,0));
        
        for(int i=1;i<=m1;i++){
            for(int j=1;j<=m2;j++){
                
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        
        return dp[m1][m2];
        
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int m1=s1.length(),m2=s2.length();
        
        return tabulation(m1,m2,s1,s2);
        vector<vector<int>> dp(m1+1,vector<int>(m2+1,-1));
        
        return memoize(m1-1,m2-1,s1,s2,dp);
    }
};