class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        if(nums.size()==2)
            return nums;
        unsigned int Xor=0;
        
        for(int num:nums)
            Xor^=num;
        Xor&=-Xor;
        
        int num1=0,num2=0;
        for(int num:nums){
            if(num&Xor)
                num1^=num;
            else
                num2^=num;
        }
    vector<int> res(2);
    res[0]=num1; res[1]=num2;
    return res;
    }
};