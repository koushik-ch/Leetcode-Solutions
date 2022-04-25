// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
    long long smallestpositive(vector<long long> nums, int n)
    { 
        long long maxSoFar=0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(nums[i]<=maxSoFar+1)
                maxSoFar+=nums[i];
            else
                return maxSoFar+1;
        }
        return maxSoFar+1;
    } 
};


// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends