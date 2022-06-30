class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int minn = nums[0];
        
        for (int n : nums) minn = min(minn, n);
        
        int res = 0;
        
        for (int n : nums) res += n - minn;
        
        return res;
    }
};