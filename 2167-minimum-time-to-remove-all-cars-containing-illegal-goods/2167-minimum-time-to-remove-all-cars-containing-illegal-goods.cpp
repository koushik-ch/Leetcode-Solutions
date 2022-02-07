class Solution {
public:
    int minimumTime(string s) {
        vector<int> nums;
        for(auto it:s){
            if(it=='0')
                nums.push_back(-1);
            else
                nums.push_back(1);
        }
        int subarr=0,sum=0;
        
        for(int i=0;i<nums.size();i++){
            subarr+=nums[i];
            sum=min(sum,subarr);
            if(subarr>0)
                subarr=0;
        }
        
        return sum+s.size();
    }
};