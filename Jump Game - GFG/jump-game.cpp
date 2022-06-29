// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int nums[], int n) {
        int maxSoFar=0;
        
        for(int i=0;i<n;i++){
            if(i>maxSoFar)
                return false;
            maxSoFar=max(maxSoFar,i+nums[i]);
        }
        
        return maxSoFar>=n-1;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends