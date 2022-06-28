class Solution {
public:
    int minDeletions(string s) {
        
        unordered_set<int> set;
        
        vector<int> freq(26,0);
        
        for(char c:s)
            freq[c-'a']++;
        int ans=0;
        
        for(int i=0;i<26;i++){
            int count=freq[i];
            
            while(count>0&&set.find(count)!=set.end()){
                ans++;
                count--;
            }
            if(count>0) set.insert(count);
        }
            return ans;
    }
};