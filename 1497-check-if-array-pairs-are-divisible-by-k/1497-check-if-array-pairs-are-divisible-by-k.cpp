class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()&1) return false;
        
        unordered_map<int,int> mp;
        
        for(int num:arr){
            int mod=(num%k+k)%k;
            
            mp[mod]++;
        }
        
        for(int num: arr){
            
            int mod=(num%k+k)%k;
            
            if(mod==0){
                if(mp[mod]&1)
                    return false;
            }
            else{
                if(mp[mod]!=mp[k-mod])
                    return false;
            }
        }
        return true;
    }
};