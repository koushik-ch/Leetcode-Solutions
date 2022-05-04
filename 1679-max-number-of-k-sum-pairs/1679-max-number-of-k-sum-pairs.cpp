class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int count=0;
        
        
        for(int num:nums){
            if(mp[k-num]>0){
                mp[k-num]--;
                count++;
            }
            else
                mp[num]++;
        }
        return count;
    }
};