class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(char c:target)
            mp2[c]++;
        
        for(char c:s)
            mp1[c]++;
        
        int minSofar=INT_MAX;
        for(char c:target){
            int val=mp1[c]/mp2[c];
            
            minSofar=min(val,minSofar);
        }
        return minSofar;
    }
};