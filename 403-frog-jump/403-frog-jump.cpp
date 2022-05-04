class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<stones.size();i++)
            mp[stones[i]]=i;
        
        int last=stones[stones.size()-1];
        
        if(stones[1]>1)
            return false;
        vector<vector<int>> dp(stones.size()+1,vector<int>(stones.size()+1,-1));
        
        return helper(mp,last,stones[1],1,dp);
        
    }
    
    bool helper(unordered_map<int,int>& mp,int last,int curr,int k,vector<vector<int>>& dp){
        if(curr==last){
            return true;
        }
        
        if(curr>last||mp.find(curr)==mp.end())
            return false;
        
        int ind=mp[curr];
        
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        
        bool ans=false;
        
        if(k>1)
            ans=ans||helper(mp,last,curr+k-1,k-1,dp);
        
        ans=ans||helper(mp,last,curr+k,k,dp);
        ans=ans||helper(mp,last,curr+k+1,k+1,dp);
        
        return dp[ind][k]=ans;
    }
};