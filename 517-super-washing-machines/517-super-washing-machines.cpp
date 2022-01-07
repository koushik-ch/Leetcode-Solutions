class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int totalClothes=0;
        
        for(int clothes:machines)
            totalClothes+=clothes;
        
        int n=machines.size();
        if(totalClothes%n!=0)
            return -1;
        
        
        int avg=totalClothes/n;
        
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        
        for(int i=1;i<n;i++)
            leftSum[i]=leftSum[i-1]+machines[i-1];
        
        
        for(int i=n-2;i>=0;i--)
            rightSum[i]=rightSum[i+1]+machines[i+1];
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int expLeftSum=i*avg;
            int expRightSum=(n-i-1)*avg;
            int left=0,right=0;
            
            if(expLeftSum>leftSum[i])
                left=expLeftSum-leftSum[i];
            
            if(expRightSum>rightSum[i])
                right=expRightSum-rightSum[i];
            
            ans=max(ans,left+right);
        }
        
    return ans; 
    }
};