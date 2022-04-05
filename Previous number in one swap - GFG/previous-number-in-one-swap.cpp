// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s){
        int breakPt=-1;
        int n=s.length();
        
        for(int i=n-2;i>=0;i--){
            if(s[i]>s[i+1]){
                breakPt=i;
                break;
            }
        }
        
        if(breakPt==-1)
            return "-1";
        bool flag=false;
        
        int breakPt2=-1;
        
        for(int i=breakPt+1;i<n;i++){
            if(s[i]<s[breakPt]){
                if(breakPt2==-1)
                    breakPt2=i;
                else if(s[i]>s[breakPt2])
                    breakPt2=i;
            }
        }
        
        swap(s[breakPt],s[breakPt2]);
        if(s[0]=='0')
        return "-1";
        
        return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends