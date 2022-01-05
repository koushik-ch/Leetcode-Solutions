class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        
        int l=0,r=nums.size()-1;
        int ptr=r;
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                res[ptr]=nums[l]*nums[l];
                l++;
                ptr--;
            }
            else{
                res[ptr]=(nums[r]*nums[r]);
                r--;
                ptr--;
            }
        }
        return res;
    }
};