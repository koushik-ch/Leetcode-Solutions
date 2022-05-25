class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum=0;
        long long currSum=0;
        int ans=0;
        
        for(int num:nums)
            totalSum+=num;
        
        for(int i=1;i<nums.size();i++){
            totalSum-=nums[i-1];
            currSum+=nums[i-1];
            
            if(currSum>=totalSum)
                ans++;
        }
        return ans;
    }
};