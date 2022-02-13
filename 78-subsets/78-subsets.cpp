class Solution {
public:
    void solve(vector<int>& nums,int ind,vector<int>& curr,vector<vector<int>>& res){
        if(ind>=nums.size()){
            res.push_back(curr);
            return;
        }
        
        curr.push_back(nums[ind]);
        solve(nums,ind+1,curr,res);
        curr.pop_back();
        solve(nums,ind+1,curr,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums,0,curr,res);
        return res;
    }
};