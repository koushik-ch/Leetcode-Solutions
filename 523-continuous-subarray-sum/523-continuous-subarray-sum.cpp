class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        
        unordered_map<int,int> mp;
        if(nums.size()==1)
            return false;
        mp[0]=-1;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(mp.find(sum%k)!=mp.end()){
                if(i-mp[sum%k]>=2)
                    return true;
            }
            else
                mp[sum%k]=i;
        }
        
        
        return false;
    }
};