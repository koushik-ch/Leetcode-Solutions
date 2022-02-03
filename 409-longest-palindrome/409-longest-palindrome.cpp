class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        int maxLen=0;
        bool flag=false;
        unordered_map<char,int> mp;
        
        for(char c:s)
            mp[c]++;
        
        for(auto it:mp){
            if(it.second%2!=0){
                maxLen+=it.second-1;
                flag=true;
            }
            else if(it.second%2==0)
                maxLen+=it.second;
        }
        if(flag)
            maxLen++;
        return maxLen;
    }
};