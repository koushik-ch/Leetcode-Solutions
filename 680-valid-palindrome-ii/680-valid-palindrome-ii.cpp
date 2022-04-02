class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        
        while(i<=j){
            if(s[i]!=s[j]){
                return isPal(s,i+1,j)||isPal(s,i,j-1);
            }
            i++;
            j--;
        }
        return true;
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