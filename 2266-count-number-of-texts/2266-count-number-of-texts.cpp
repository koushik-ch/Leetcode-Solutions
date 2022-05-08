class Solution {
public:
    int mod = 1e9+7;
    int countTexts(string pressedKeys) {
        
        int n=pressedKeys.length();
        vector<long long> dp(n+1,-1);
        vector<int> keys={0,0,3,3,3,3,3,4,3,4};
        return getCount(pressedKeys,0,dp,keys);
    }
    
    int getCount(string& s,int ind,vector<long long>& dp,vector<int>& keys){
        if(ind==s.length())
            return 1;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        long long count=0;
        
        int key=s[ind]-'0';
        
        for(int i=0;i<keys[key]&&ind+i<s.length()&&s[ind]==s[ind+i];i++){
            count+=getCount(s,ind+i+1,dp,keys);
            count%=mod;
        }
        return dp[ind]=count;
    }
};