// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
         if(t.size()>s.size())
            return "-1";
        unordered_map<char,int> mp;
        
        int ans=INT_MAX,start=0;
        int i=0,j=0,count=0;
        for(char c:t){
            mp[c]++;
            if(mp[c]==1)
                count++;
        }
        
        
        
        while(j<s.size()){
            
            mp[s[j]]--;
            
            if(mp[s[j]]==0)
                count--;
            
            if(count==0){
                while(count==0){
                    if(j-i+1<ans){
                    ans=j-i+1;
                    start=i;
                }
                    
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                        count++;
                    i++;
                }
            
            }
            j++;
        }
    if(ans==INT_MAX)
            return "-1";
        return s.substr(start,ans);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends