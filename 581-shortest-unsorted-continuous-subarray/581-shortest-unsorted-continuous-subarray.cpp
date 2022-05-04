class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(),maxVal=INT_MIN,minVal=INT_MAX;
        bool flag=false;
        
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])
                flag=true;
            
            if(flag)
                minVal=min(minVal,nums[i]);
        }
        
        flag=false;
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1])
                flag=true;
            
            if(flag)
                maxVal=max(maxVal,nums[i]);
        }
        
        int l,r;
        
        for(l=0;l<n;l++)
            if(minVal<nums[l])
                break;
        
        for(r=n-1;r>=0;r--)
            if(maxVal>nums[r])
                break;
        if(l>r)
            return 0;
        return r-l+1;
    }
};