class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int open=0,close=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                open++;
            else
                close++;
            
            if(open==close){
                ans=max(open+close,ans);
            }
            else if(close>open)
                open=close=0;
        }
        open=close=0;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                open++;
            else
                close++;
            
            if(open==close){
                ans=max(open+close,ans);
            }
            else if(close<open)
                open=close=0;
        }
        return ans;
    }
};