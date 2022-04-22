class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        
        string res;
        
        for(char c:s){
            
            if(!st.empty()&&st.back().first==c){
                if(st.back().second+1==k)
                    st.pop_back();
                else{
                    st.back().second++;
                }
            }
            else{
                st.push_back({c,1});
            }
        }
        
        for(auto s:st)
            res.append(s.second,s.first);
        
        return res;
    }
};