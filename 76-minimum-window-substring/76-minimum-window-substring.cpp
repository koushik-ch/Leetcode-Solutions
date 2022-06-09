class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())
            return "";
        unordered_map<char,int> mp;
        
        int ans=INT_MAX,start=0;
        int i=0,j=0,count=0;
        
        for(char c:t){
            mp[c]++;
            if(mp[c]==1)
                count++;
        }
        
        
        
        while(j<s.size()){
            
            mp[s[j]]--;
            
            if(mp[s[j]]==0)
                count--;
            
            if(count==0){
                while(count==0){
                    if(j-i+1<ans){
                    ans=j-i+1;
                    start=i;
                }
                    
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                        count++;
                    i++;
                }
            
            }
            j++;
        }
    if(ans==INT_MAX)
            return "";
        return s.substr(start,ans);
    }
};