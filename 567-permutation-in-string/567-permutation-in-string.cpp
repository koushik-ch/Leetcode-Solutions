class Solution {
public:
    bool compareHash(unordered_map<char,int>& mp1,unordered_map<char,int>& mp2){
        
        for(auto it:mp2){
            if(mp1[it.first]==it.second)
                continue;
            return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int n=s1.length();
        
        for(int i=0;i<n;i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        
        for(int i=n;i<s2.length();i++){
            if(compareHash(mp1,mp2))
                return true;
            mp2[s2[i-n]]--;
            mp2[s2[i]]++;
        }
        if(compareHash(mp1,mp2))
                return true;
        return false;
    }
};