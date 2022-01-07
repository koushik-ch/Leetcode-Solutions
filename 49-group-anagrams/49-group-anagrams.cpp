class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        
        for(string  word:strs){
            
            string copy=word;
            
            sort(copy.begin(),copy.end());
            
            mp[copy].push_back(word);
        }
        vector<vector<string>> res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};