class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        
        if(s.length()<4)
            return res;
       
        buildIP(s,"",0,0,res,0);
        return res;
    }
    
    void buildIP(string s,string curr,int ind,int lastDot,vector<string>& res,int dotCount){
        
        if(ind>=s.length()){
            if(dotCount==3){
                if(ind-lastDot>1&&s[lastDot]=='0')
                return;
                res.push_back(curr);
            }
            return;
        }
               
        
        if(ind-lastDot+1<4){
            if(isValid(s.substr(lastDot,ind-lastDot+1)))
                buildIP(s,curr+s[ind],ind+1,lastDot,res,dotCount);
        }
        if(ind-lastDot){
            
            if(ind-lastDot>1&&s[lastDot]=='0')
                return;
            buildIP(s,curr+'.',ind,ind,res,dotCount+1);
            
        }
        
    }
    
    
    bool isValid(string s){
        if(stoi(s)<256)
            return true;
        
        return false;
    }
};