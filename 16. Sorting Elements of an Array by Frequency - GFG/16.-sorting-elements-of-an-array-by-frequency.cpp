// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        map<int,int> mp;
        
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
            
        for(auto it:mp){
            pq.push({it.second,-1*it.first});
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            pair<int,int> val=pq.top();
            pq.pop();
            
            for(int i=0;i<val.first;i++)
                res.push_back(-1*val.second);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends