class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minSoFar=INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            ans=max(ans,prices[i]-minSoFar);
            minSoFar=min(minSoFar,prices[i]);
        }
        return ans;
    }
};