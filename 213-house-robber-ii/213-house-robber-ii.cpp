class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(2,-1));
        
        return robHouse(nums,0,false,dp);
        
    }
    
    int robHouse(vector<int>& nums,int ind,bool flag, vector<vector<int>>& dp){
        if(ind>=nums.size())
            return 0;
        
        if(dp[ind][flag]!=-1)
            return dp[ind][flag];
        
        int pick=0;
                
        if(ind==0){
            pick=robHouse(nums,ind+2,true,dp)+nums[ind];
        }
        else if(ind==nums.size()-1&&flag)
            pick=0;
        else
            pick=robHouse(nums,ind+2,flag,dp)+nums[ind];
        
        int nonPick=robHouse(nums,ind+1,flag,dp);
        return dp[ind][flag]=max(pick,nonPick);
    }
};