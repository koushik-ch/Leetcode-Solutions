class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size(),m=nums[0].size();
        int low=0,high=(n*m)-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int i=mid/m;
            int j=mid%m;
            
            if(nums[i][j]==target)
                return true;
            
            if(nums[i][j]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};