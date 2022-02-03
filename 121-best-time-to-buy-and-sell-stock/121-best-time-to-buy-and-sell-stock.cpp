class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minPrice=INT_MAX;
        
        for(int price:prices){

            ans=max(ans,price-minPrice);
            minPrice=min(minPrice,price);
        }
        if(ans<=0)
            return 0;
        return ans;
    }
};