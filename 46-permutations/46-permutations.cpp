class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums,0,curr,res);
        return res;
    }
    
    void solve(vector<int>& nums,int ind,vector<int>& curr,vector<vector<int>>& res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            // curr.push_back(nums[i]);
            
            solve(nums,ind+1,curr,res);
            
            // curr.pop_back();
            swap(nums[i],nums[ind]);
        }
    }
};