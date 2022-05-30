class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n(size(nums)), res(0);
        unordered_set<string> all; // stores unique substrings which satisfy the given condition.
        
        for (int i=0; i<n; i++) {
            int cnt(0);
            string currSubArray; // stores subarray starting from index i.
            for (int j=i; j<n; j++) {
                currSubArray.push_back(nums[j]); // Appending charcter with nums[j] ascii value.
                if (nums[j] % p == 0)  cnt++;
                // if the current array have at most k elements divisible by  then add it to the set.
                if (cnt <= k)    all.insert(currSubArray);
            }
        }
        return size(all);
    }
};