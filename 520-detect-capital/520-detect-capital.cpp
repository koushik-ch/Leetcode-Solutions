class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool flag=true;
        
        int capCount=0;
        
        for(int i=0;i<word.size();i++){
            if(word[i]<='Z'){
                capCount++;
                if(i>0)
                    flag=false;
            }
        }
        
        if(capCount==0||capCount==word.size()||flag)
            return true;
        return false;
        
    }
};