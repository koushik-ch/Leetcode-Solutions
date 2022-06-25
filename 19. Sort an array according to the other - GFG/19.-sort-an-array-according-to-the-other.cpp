// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
     
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m) 
    {
        map<int,int> mp;
        unordered_map<int,int> mp2;
        queue<int> q;
        
        for(int num:a2){
            if(mp2.find(num)==mp2.end())
                q.push(num);
            mp2[num]++;
        }
        
        for(int num:a1)
            mp[num]++;
        vector<int> res;
        
        
        
        while(!q.empty()){
            int num=q.front();
            if(mp.find(num)!=mp.end()){
                for(int i=0;i<mp[num];i++)
                    res.push_back(num);
                mp.erase(num);
            }
            q.pop(); 
        }
        
        for(auto it:mp){
            for(int i=0;i<it.second;i++)
                res.push_back(it.first);
        }
        return res;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends