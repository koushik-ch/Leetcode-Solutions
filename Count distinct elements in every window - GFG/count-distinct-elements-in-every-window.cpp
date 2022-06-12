// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int nums[], int n, int k)
    {
       unordered_map<int,int> mp;
       int count=0;
       vector<int> ans;
       for(int i=0;i<k;i++){
           mp[nums[i]]++;
           if(mp[nums[i]]==1)
                count++;
       }
       
       ans.push_back(count);
       
       int l=0,r=k;
       
       while(r<n){
           mp[nums[l]]--;
           if(mp[nums[l]]<1)
            count--;
            l++;
            
            
            mp[nums[r]]++;
            if(mp[nums[r]]==1)
            count++;
            
            ans.push_back(count);
            r++;
       }
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends