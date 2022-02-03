class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        vector<int> curr=intervals[0];
        int n=intervals.size();
        
        
        for(int i=0;i<n;i++){
            if(curr[1]>=intervals[i][0])
                curr[1]=max(curr[1],intervals[i][1]);
            else{
                res.push_back(curr);
                curr=intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};