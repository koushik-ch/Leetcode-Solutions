class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;
        
        for(int i=1;i<n;i++){
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k-=1; //0 Based indexing
        string ans;
        
        while(nums.size()){
            ans+=to_string(nums[k/fact]);
            
            nums.erase(nums.begin()+k/fact);
            k=k%fact;
            if(nums.size())
            fact=fact/nums.size();
        }
        return ans;
    }
};