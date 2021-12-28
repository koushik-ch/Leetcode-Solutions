class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>  mp;
         mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string> res;
        string curr;
        if(digits.size()==0)
            return res;
        letterCombinationHelper(digits,res,curr,0,mp);
        return res;
    }
    
    void letterCombinationHelper(string& digits,vector<string>& res,string& curr,int ind,unordered_map<char,string>& mp){
        if(ind==digits.size()){
            res.push_back(curr);
            return;
        }
        string combs=mp[digits[ind]];
        
        for(int i=0;i<combs.size();i++){
            curr.push_back(combs[i]);
            letterCombinationHelper(digits,res,curr,ind+1,mp);
            curr.pop_back();
        }
        
    }
    
    
};