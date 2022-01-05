class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes=0;
        int currentCount=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currentCount++;
                maxOnes=max(maxOnes,currentCount);
            }
            else 
                currentCount=0;
        }
        return maxOnes;
    }
};