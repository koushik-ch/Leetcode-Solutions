class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        int ans=0,n=nums.size(),one=0,zero=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                zero++;
            else
                one++;
            
            if(one==zero)
                ans=max(i+1,ans);
            
            
                int diff=one-zero;
                
                if(mp.count(diff)>0)
                    ans=max(ans,i-mp[diff]);
                else
                    mp[diff]=i;
            
        }
        return ans;
    }
};