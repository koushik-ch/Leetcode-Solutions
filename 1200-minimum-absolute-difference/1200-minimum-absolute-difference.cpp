class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff=INT_MAX;
        
        sort(arr.begin(),arr.end());
        
        for(int i=1;i<arr.size();i++){
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        }
        
        vector<vector<int>> res;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==minDiff)
                res.push_back({arr[i-1],arr[i]});
        }
        return res;
    }
};