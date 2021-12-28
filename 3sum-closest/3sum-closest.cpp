class Solution {
    
public:
    int movePtr(vector<int>& nums,int ptr,bool flag){
        int currVal=nums[ptr];
        if(flag){
            while(ptr<nums.size()&&nums[ptr]==currVal)
                ptr++;
        }
        else{
            while(ptr>=0&&nums[ptr]==currVal)
                ptr--;
        }
        return ptr;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int minDiff=INT_MAX;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            
            int l=i+1,r=n-1;
            
            while(l<r){
                int sum=nums[l]+nums[r]+nums[i];
                if(abs(target-sum)<minDiff){
                    ans=sum;
                    minDiff=abs(target-sum);
                }
                if(sum<target){
                    l=movePtr(nums,l,true);
                }
                else{
                    r=movePtr(nums,r,false);
                }
            }
        
        }
        
        return ans;
    }
    
};