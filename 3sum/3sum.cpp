class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int left=i+1,right=n-1;
            
            if(i>0&&nums[i]==nums[i-1])
                continue;
            
            while(left<right){
                int currSum=nums[i]+nums[left]+nums[right];
                
                if(currSum<0){
                    left++;
                    int curr=nums[left-1];
                    while(left<n&&curr==nums[left])
                        left++;
                }
                if(currSum>0){
                    right--;
                    int curr=nums[right+1];
                    while(right>=0&&curr==nums[right])
                        right--;
                }
                
                if(currSum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    
                    int curr=nums[left-1];
                    while(left<n&&curr==nums[left])
                        left++;
                    
                    right--;
                    curr=nums[right+1];
                    while(right>=0&&curr==nums[right])
                        right--;
                    
                }
            }
            
            int curr=nums[i];
            
        }
        return res;
        
    }
};