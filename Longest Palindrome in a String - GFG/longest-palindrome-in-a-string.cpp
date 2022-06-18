// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) 
    {
        int len=0;
        int start=0;
        int l;
        int r;
        //even case
        for(int i=0; i<S.length()-1; i++)
        {
            l=i;
            r=i+1;
            while(l>=0 && r<S.length() && S[l]==S[r])
            {
                if(r-l+1 > len){
                    len=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        
        //odd case
        for(int i=1; i<S.length()-1; i++)
        {
            l=i-1;
            r=i+1;
            while(l>=0 && r<S.length() && S[l]==S[r])
            {
                if(r-l+1 > len){
                    len=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        if(len==0){
            len++;
        }
        return S.substr(start, len);
    }

};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends