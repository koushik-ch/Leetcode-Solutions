class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        
        for(char c:s)
            mp[c]++;
        
        char ans;
        
        for(char c:t){
            if(mp[c]<1)
                mp[c]++;
            else
                mp[c]--;
        }
        
        for(auto it:mp){
            if(it.second>=1){
                ans=it.first;
                break;
            }
                
            }
            return ans;
    }
};