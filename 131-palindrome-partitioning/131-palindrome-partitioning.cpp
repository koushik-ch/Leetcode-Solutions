class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        solve(s,0,curr,res);
        return res;
    }
    
    
    void solve(string s,int ind,vector<string>& curr,vector<vector<string>>& res){
        if(ind==s.length()){
            res.push_back(curr);
            return;
        }
        
        for(int i=ind;i<s.length();i++){
            if(isPal(s,ind,i)){
                curr.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,curr,res);
                curr.pop_back();
            }
        }
    }
    
    bool isPal(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};