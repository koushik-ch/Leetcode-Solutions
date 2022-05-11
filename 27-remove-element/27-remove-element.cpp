class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int vacancy=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[vacancy]=nums[i];
                vacancy++;
            }
        }
        return vacancy;
    }
};