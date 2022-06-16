class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        
        for(int i=0;i<s.length();i++){
            expand(i,i,s,res);
            expand(i-1,i,s,res);
        }
        
        return res;
    
    }
    
    void expand(int l,int r,string& s,string& ans){
        int n=s.size();
        
        while(l>=0&&r<=n&&s[l]==s[r]){
            int size=r-l+1;
            
            if(size>ans.size()){
                ans=s.substr(l,size);
            }
            
            l--;
            r++;
        }
    }
};