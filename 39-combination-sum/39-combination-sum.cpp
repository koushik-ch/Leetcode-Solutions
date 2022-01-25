class Solution {
public:
    void solve(vector<int>& candidates,vector<int> curr,int ind,int target,vector<vector<int>>& res){
        if(ind>=candidates.size()){
            return;
        }
        
        if(!target){
            res.push_back(curr);
            return;
        }
        
        if(target>=candidates[ind]){
            curr.push_back(candidates[ind]);
            solve(candidates,curr,ind,target-candidates[ind],res);
            curr.pop_back();
        }
        
        solve(candidates,curr,ind+1,target,res);
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        solve(candidates,{},0,target,res);
        return res;
    }
};