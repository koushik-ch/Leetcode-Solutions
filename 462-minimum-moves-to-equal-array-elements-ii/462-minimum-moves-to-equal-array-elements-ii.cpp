class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        
        sort(nums.begin(),nums.end());
        
        int sum=0;
        
        while(l<=r){
            sum+=(nums[r]-nums[l]);
            l++;
            r--;
        }
        return sum;
    }
};