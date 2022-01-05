class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int ans=0,lsum=0,rsum=0;
        int i;
        
        for(i=0;i<k;i++){
            lsum+=nums[i];
        }
        cout<<i<<endl;
        i--;
        ans=lsum;
        int n=nums.size();
        for(int j=n-1;j>=n-k;j--){
            lsum-=nums[i];
            lsum+=nums[j];
            i--;
            ans=max(ans,lsum);
            
        }
        return ans;
    }
};