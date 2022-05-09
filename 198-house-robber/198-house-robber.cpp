class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        // vector<int> dp(nums.size()+1);
        int val1=0,val2=nums[0];
        
        // dp[0]=nums[0];
        int curri=0;
        
        for(int i=1;i<nums.size();i++){
            
            val1+=nums[i];
            curri=max(val1,val2);
            
            val1=val2;
            val2=curri;
            
            
//             int val1=nums[i];
//             if(i>1)
//                 val1+=dp[i-2];
            
//             dp[i]=max(val1,dp[i-1]);
        }
        return curri;
        
        // return dp[nums.size()-1];
        
        
    }
    
   
};