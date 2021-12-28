class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        helper(res,curr,0,0,n);
        return res;
        
    }
    
    void helper(vector<string>& res,string& curr,int openCount,int closeCount,int n){
        if(openCount+closeCount==n*2){
            res.push_back(curr);
            return;
        }
        
        
        if(openCount==closeCount){
            curr.push_back('(');
            helper(res,curr,openCount+1,closeCount,n);
            curr.pop_back();
            return;
        }
        
        else if(openCount==n){
            curr.push_back(')');
            helper(res,curr,openCount,closeCount+1,n);
            curr.pop_back();
            return;
        }
        
        else{
            curr.push_back('(');
            helper(res,curr,openCount+1,closeCount,n);
            curr.pop_back();
            curr.push_back(')');
            helper(res,curr,openCount,closeCount+1,n);
            curr.pop_back();
        }
        
        
    }
    
    
};