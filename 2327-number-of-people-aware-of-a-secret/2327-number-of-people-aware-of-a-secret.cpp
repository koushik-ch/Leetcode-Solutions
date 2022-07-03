class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<long long int, long long int> tell;
        unordered_map<long long int, long long int> forg;
        
        tell[1+delay] = 1;
        forg[1+forget] = 1;
        
        long long int curr_spread = 0; 
        long long int ans = 0;
        for(int i = 1 + delay; i <= n; ++ i){
            curr_spread += tell[i] % (1000000000 + 7);
            curr_spread -= forg[i] % (1000000000 + 7);
            tell[i+delay] += curr_spread;
            forg[i+forget] += curr_spread;  
        }
        
        for(auto& it: forg){
            if(it.first > n) ans += it.second;
        }

        return ans % (1000000000 + 7);
    }
};