class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        ans=sum;
        int l=k-1;
        int r=cardPoints.size()-1;
        
        while(l>=0){
            sum-=cardPoints[l];
            l--;
            sum+=cardPoints[r];
            r--;
            ans=max(sum,ans);
        }
        return ans;
    }
};