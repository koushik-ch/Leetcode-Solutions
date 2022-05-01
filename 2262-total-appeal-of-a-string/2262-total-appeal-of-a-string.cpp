class Solution {
public:
    long long appealSum(string s) {
        
        long long res=0,total=0;
        vector<int> map(26);
        
        for(int i=0;i<s.length();i++){
            total+=i+1-map[s[i]-'a'];
            
            map[s[i]-'a']=i+1;
            
            res+=total;
        }
        return res;
    }
};