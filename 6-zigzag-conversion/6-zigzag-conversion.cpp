class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        
        string res;
        int n=s.length(),j;
        int incrementVal=(numRows-1)*2;
        
        for(int i=0;i<numRows;i++){
            if(i==0||i==numRows-1){
                j=i;
                while(j<n){
                    res+=s[j];
                    j+=incrementVal;
                }
            }
            
            else{
                j=i;
                while(j<n){
                    res+=s[j];
                    
                    if((j+(incrementVal-(2*i)))<n)
                        res+=s[j+(incrementVal-(2*i))];
                    
                    j+=incrementVal;
                }
            }
        }
        return res;
    }
};