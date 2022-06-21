class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> set;
        
        for(string s:words){
            set.insert(s);
        }
        
        for(auto s:set){
            for(int i=1;i<s.size();i++){
                set.erase(s.substr(i));
            }
        }
        int size=0;
        
        for(auto s:set)
            size+=s.size()+1;
        
        return size;
    }
};