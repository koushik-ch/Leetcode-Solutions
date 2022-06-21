// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int count=0;
        long long ans=0;
        
        unordered_map<int,long long> mp;
        mp[0]++;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                count--;
            else
                count++;
            // if(count==0)
            //     ans++;
            // else{
                if(mp.find(count)!=mp.end())
                    ans+=mp[count];
                // else
                    mp[count]++;
            // }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends