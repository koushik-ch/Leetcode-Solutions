class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int ans=0;
        int sum=0;
        for(int num:nums){
            sum+=num;
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};