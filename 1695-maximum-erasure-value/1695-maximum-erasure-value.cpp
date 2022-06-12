class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        int currSum=0;
        int ans=0;
        
        int l=0,r=0;
        
        while(r<nums.size()&&l<nums.size()){
            mp[nums[r]]++;
            
            while(mp[nums[r]]>1){
                mp[nums[l]]--;
                
                currSum-=nums[l];
                l++;
            }
            
            currSum+=nums[r];
            ans=max(currSum,ans);
            r++;
        }
        return ans;
    }
};