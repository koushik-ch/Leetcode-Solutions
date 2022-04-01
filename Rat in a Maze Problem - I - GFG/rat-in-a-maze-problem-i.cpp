// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
        vector<char> vals={'U','D','L','R'};
        vector<int> dx{-1,1,0,0};
        vector<int> dy={0,0,-1,1};
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string curr;
        solve(m,0,0,n,curr,res);
        return res;
    }
    
    void solve(vector<vector<int>> &m,int i,int j,int n,string& curr,vector<string>& res){
        if(i<0||i>=n||j<0||j>=n||m[i][j]==0)
            return;
        
        if(i==n-1&&j==n-1){
            res.push_back(curr);
            return;
        }
        m[i][j]=0;
        
        for(int k=0;k<4;k++){
            curr.push_back(vals[k]);
            solve(m,i+dx[k],j+dy[k],n,curr,res);
            curr.pop_back();
        }
        m[i][j]=1;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends