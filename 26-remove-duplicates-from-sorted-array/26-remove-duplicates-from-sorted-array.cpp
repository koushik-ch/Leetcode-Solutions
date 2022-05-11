class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int vacancy=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[vacancy])
                continue;
            
            vacancy++;
            nums[vacancy]=nums[i];
        }
        return vacancy+1;
    }
};