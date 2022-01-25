// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solve(arr,0,0,res);
        return res;
    }
    
    
    void solve(vector<int>& arr,int i,int currSum,vector<int>& res){
        if(i>=arr.size()){
            res.push_back(currSum);
            return;
        }
        
        solve(arr,i+1,currSum,res);
        solve(arr,i+1,currSum+arr[i],res);
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends