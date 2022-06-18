// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string s)
		{   set<string> set;
		    vector<string> res;
		    
		    recurse(s,0,set);
		    
		    for(auto str:set)
		        res.push_back(str);
		    return res;
		}
	
	
	void recurse(string& s,int ind,set<string>& set){
	    if(ind==s.length()){
	        set.insert(s);
	    }
	    
	    for(int i=ind;i<s.length();i++){
	        swap(s[ind],s[i]);
	        recurse(s,ind+1,set);
	        swap(s[ind],s[i]);
	    }
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends